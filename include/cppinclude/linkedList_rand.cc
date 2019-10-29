#include "linkedList_rand.h"
#include "json/json.h"
#include <queue>
#include <unordered_map>

// transform the json representation of linked list into the linked list
Node *
LinkedListRandom::list2list(std::string rawJson)
{
  // parse the json first
  const int rawJsonLength = static_cast<int>(rawJson.length());
  JSONCPP_STRING err;
  Json::Value root;
  Json::CharReaderBuilder builder;
  const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
  if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root,
                     &err))
  {
    assert(false);
  }
  // create the linked list
  std::unordered_map<int, Node *> m;  //<id, Node corresponding with id>
  std::unordered_map<Node *, int> m3; //<Node, the id this Node's random ptr points to>
  std::queue<Json::Value> q;
  Node *head = new Node(0, nullptr, nullptr);
  auto curr = head;
  q.push(root);
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    int id = std::stoi(node["$id"].asString());
    int val = node["val"].asInt();
    int ref = std::stoi(node["random"]["$ref"].asString());
    curr->next = new Node(val, nullptr, nullptr);
    m3[curr->next] = ref;
    m[id] = curr->next;
    if (!node["next"].isNull())
      q.push(node["next"]);
    curr = curr->next;
  }
  // add the random pointer
  curr = head->next;
  while (curr)
  {
    curr->random = m[m3[curr]];
    curr = curr->next;
  }
  return head->next;
}

Json::Value
printListHelper(Node *head)
{
  Json::Value root;
  if (head == nullptr)
    return root;
  if (head->next == nullptr)
  {
    Json::Value rand_ptr;
    root["$id"] = std::to_string(head->val);
    root["val"] = head->val;
    root["next"] = Json::Value();
    if (head->random)
    {
      rand_ptr["$ref"] = std::to_string(head->random->val);
      root["random"] = rand_ptr;
    }
    else
    {
      root["random"] = Json::Value();
    }
    return root;
  }
  auto data = printListHelper(head->next);
  Json::Value rand_ptr;
  root["$id"] = std::to_string(head->val);
  root["val"] = head->val;
  if (head->random)
  {
    rand_ptr["$ref"] = std::to_string(head->random->val);
    root["random"] = rand_ptr;
  }
  else
  {
    root["random"] = Json::Value();
  }
  root["next"] = data;
  return root;
}

// transform a linked list to the json representation of linked list
std::string
LinkedListRandom::printList(Node *head)
{
  // build JSON DOM
  Json::Value root = printListHelper(head);
  Json::StreamWriterBuilder builder;
  builder["indentation"] = ""; // JSON document written in one line
  const std::string json_file = Json::writeString(builder, root);
  return json_file; 
}

// delete the linked list
void LinkedListRandom::freeList(Node *&head)
{
  if (head == nullptr)
  {
    return;
  }
  LinkedListRandom::freeList(head->next);
  delete (head);
}

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
  std::unordered_map<int, Node*>  m; //<id, Node corresponding with id>
  std::unordered_map<Node*, int> m3; //<Node, the id this Node's random ptr points to>
  std::queue<Json::Value> q;
  Node *head;
  head = new Node(std::stoi(root["$id"].asString()), nullptr, nullptr);
  std::cout << head->val << std::endl;
  if (!root["next"].isNull()) {
    q.push(root["next"]);
  }
  m[std::stoi(root["$id"].asString())] = head;
  m3[head] = std::stoi(root["random"]["$ref"].asString());
  auto curr = head;
  while(!q.empty()) {
    auto node = q.front(); q.pop();
    int id = std::stoi(node["$id"].asString());
    int ref = std::stoi(node["random"]["$ref"].asString());
    curr->next = new Node(id, nullptr, nullptr);
    m3[curr->next] = ref;
    m[id] = curr->next;
    //m2[id] = curr;
    //m2[ref] = nullptr;
    if (!node["next"].isNull()) q.push(node["next"]);
    curr = curr->next;
  }
  // add the random pointer
  curr = head;
  while(curr) {
    curr->random = m[m3[curr]];
    curr = curr->next;
  }
  return head;
}

// transform a linked list to the json representation of linked list
std::string
LinkedListRandom::printList(Node *head)
{
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

#include "linkedList_rand.h"
#include "rapidjson/document.h"
#include <unordered_map>
#include <queue>

static const char *kTypeNames[] =
    {"Null", "False", "True", "Object", "Array", "String", "Number"};

using namespace rapidjson;

// The JSON format follows Leetcode definition:
// Ex: LC138 defines linked list like:
// {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
// returns nullptr if either json is empty or there is an error during parsing
Node *
LinkedListRandom::list2list(const char *json)
{
  std::unordered_map<int, Node *> m; // <id, Node*>
  std::queue <Value> q;
  Node *head;
  Document document;
  if (document.Parse(json).HasParseError())
    return nullptr;
  for (auto &&item : document.GetObject())
  {
    printf("Type of member %s is %s\n",
           item.name.GetString(), kTypeNames[item.value.GetType()]);
    if (strncmp(KTypeNames[item.value.GetType()],"Object") == 0) {
      q.push(item.value);
    }
  }
  head = new Node(std::stoi(document["$id"].GetString()), nullptr, nullptr);
  printf("head->val: %d\n", head->val);
  
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
}

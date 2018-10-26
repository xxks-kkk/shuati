/*************************************************************************
  > File Name:       dictionary.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/26/18
  > Description:
    
    The dictionary API implementation
 ************************************************************************/

#include "dictionary.h"

Node::Node() : isEnd(false) {}

Node::Node(std::string definition) : definition(std::move(definition)), isEnd(false) {}

bool
Node::containsKey(char ch)
{
    return links[ch - char(0)] != nullptr;
}

Node *&
Node::get(char ch)
{
    return links[ch - char(0)];
}

void
Node::put(char ch, Node *&&node)
{
    links[ch - char(0)] = node;
}

void
Node::setEnd(bool val)
{
    isEnd = val;
}

bool
Node::getEnd()
{
    return isEnd;
}

Node::~Node()
{
    for (int i = 0; i < 256; ++i)
    {
        if (links[i] != nullptr)
        {
            delete links[i];
        }
    }
}

void
Node::setDefinition(std::string definition)
{
    this->definition = definition;
}

std::string
Node::getDefinition()
{
    return this->definition;
}

Dictionary::Dictionary()
{
    root = new Node{};
}

/**
 * Inserting a word and its definition
 * @param word
 * @param definition
 */
void
Dictionary::insert(std::string word, std::string definition)
{
    auto node = root;
    for (auto &ch : word)
    {
        if (!node->containsKey(ch))
        {
            node->put(ch, new Node{});
        }
        node = node->get(ch);
    }
    node->setEnd(true);
    node->setDefinition(definition);
}

void
retrieveHelper(Node *node, std::vector<std::string> &res, std::string tmp)
{
    if (node->getEnd())
    {
        res.push_back(tmp);
    }
    for (int i = 0; i < 256; ++i)
    {
        if (node->links[i] != nullptr)
        {
            tmp.push_back(char(i + 0));
            retrieveHelper(node->links[i], res, tmp);
            tmp.pop_back();
        }
    }
}

/**
 * Retrieving all words that start with a given prefix
 * @param prefix
 * @return
 */
std::vector<std::string>
Dictionary::retrieve(std::string prefix)
{
    std::vector<std::string> res;
    auto node = root;
    for (auto &ch: prefix)
    {
        if (node->containsKey(ch))
        {
            node = node->get(ch);
        }
        else
        {
            return res;
        }
    }
    retrieveHelper(node, res, "");
    for(int i = 0; i < res.size(); ++i)
    {
        res[i] = prefix + res[i];
    }
    return res;
}

/**
 * Retrieving the definition of a given word
 * @param word
 * @return
 */
std::string
Dictionary::getDefinition(std::string word)
{
    auto node = root;
    for(auto& ch : word)
    {
        if (node->containsKey(ch))
        {
            node = node->get(ch);
        }
        else
        {
            return "";
        }
    }
    if (node->getEnd())
    {
        return node->getDefinition();
    }
    return "";
}

/**
 * Deleting a word from the dictionary
 * @param word
 * @return
 */
int
Dictionary::remove(std::string word)
{
    auto node = root;
    for(auto& ch : word)
    {
        if(node->containsKey(ch))
        {
            node = node->get(ch);
        }
        else
        {
            return -1;
        }
    }
    node->setEnd(false);
    return 0;
}
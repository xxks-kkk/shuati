/*************************************************************************
  > File Name:       dictionary.h
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/26/18
  > Description:
    
    The dictionary API
 ************************************************************************/

#ifndef SHUATI_DICTIONARY_H
#define SHUATI_DICTIONARY_H

#include <string>
// FIXME: replace with my own custom designed vector
#include <vector>
#include <sstream>

class Node
{
public:
    explicit Node();
    explicit Node(std::string definition);
    bool
    containsKey(char ch);
    Node *&
    get(char ch);
    void
    put(char ch, Node *&&node);
    void
    setEnd(bool val);
    bool
    getEnd();
    ~Node();
    void
    setDefinition(std::string definition);
    Node *links[256] = {nullptr};
    std::string
    getDefinition();
private:
    bool isEnd;
    std::string definition;
};

class Dictionary
{
public:
    Dictionary();
    void
    insert(std::string word, std::string definition);
    std::vector<std::string>
    retrieve(std::string prefix);
    std::string
    getDefinition(std::string word);
    int
    remove(std::string word);
private:
    Node *root;
};

#endif //SHUATI_DICTIONARY_H
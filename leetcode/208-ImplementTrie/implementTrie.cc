//    Implement a trie with insert, search, and startsWith methods.
//
//    Note:
//    You may assume that all inputs are consist of lowercase letters a-z.

#include <string>
#include <vector>
#include <cassert>

using namespace std;

class TrieNode
{
public:
    explicit TrieNode() : isEnd (false) {}

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode*& get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* && node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        isEnd = true;
    }

    bool getEnd()
    {
        return isEnd;
    }

    ~TrieNode()
    {
        for(int i = 0; i < R; ++i)
        {
            if(links[i] != nullptr)
            {
                delete links[i];
            }
        }
    }

private:
    const static int R = 26;
    TrieNode* links[R] = {nullptr};
    bool isEnd;
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode{};
    }

    /** Inserts a word into the trie. */
    void
    insert(string word)
    {
        auto node = root;
        for(auto & ch: word)
        {
            if(!node->containsKey(ch))
            {
                node->put(ch, new TrieNode{});
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool
    search(string word)
    {
        auto node = searchPrefix(std::move(word));
        return node != nullptr && node->getEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool
    startsWith(string prefix)
    {
        auto node = searchPrefix(std::move(prefix));
        return node != nullptr;
    }

    ~Trie()
    {
        delete root;
    }
private:
    TrieNode* root;

    // search a prefix or whole key in trie and
    // returns the node where search ends
    TrieNode* searchPrefix(string word)
    {
        auto node = root;
        for(auto & ch : word)
        {
            if(node->containsKey(ch))
            {
                node = node->get(ch);
            }
            else
            {
                TrieNode* tmp = nullptr;
                return tmp;
            }
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

void
test()
{
    auto obj = new Trie();
    obj->insert("a");
    assert(obj->search("a"));
    obj->insert("ab");
    assert(!obj->search("cd"));
    assert(obj->startsWith("a"));
    delete obj;
}

int
main()
{
    test();
}
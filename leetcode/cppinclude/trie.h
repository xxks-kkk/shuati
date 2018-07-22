#include "shared_headers.h"

// This implementation is used for non 208-ImplementTrie problems
class TrieNode
{
public:
    explicit TrieNode();

    bool
    containsKey( char ch );

    TrieNode *&
    get( char ch );

    void
    put( char ch, TrieNode *&&node );

    void
    setEnd();

    bool
    getEnd();

    /**
     * Get number of links for the given node
     * @param node TrieNode
     * @return the number of links inside the node
     */
    int
    getLinks();

    ~TrieNode();

private:
    const static int R = 26;
    TrieNode *links[R] = {nullptr};
    bool isEnd;
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie();

    /** Inserts a word into the trie. */
    void
    insert( std::string word );

    /** Returns if the word is in the trie. */
    bool
    search( std::string word );

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool
    startsWith( std::string prefix );

    /**
     * Find the longest common prefix among words in trie
     * @return the longest common prefix;
     */
    std::string
    longestCommonPrefix();

    ~Trie();

private:
    TrieNode *root;

    // search a prefix or whole key in trie and
    // returns the node where search ends
    TrieNode *
    searchPrefix( std::string word );
};
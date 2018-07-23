#include "trie.h"


TrieNode::TrieNode() : isEnd( false )
{
}


bool
TrieNode::containsKey( char ch )
{
    return links[ch - 'a'] != nullptr;
}


TrieNode *&
TrieNode::get( char ch )
{
    return links[ch - 'a'];
}


void
TrieNode::put( char ch, TrieNode *&&node )
{
    links[ch - 'a'] = node;
}


void
TrieNode::setEnd()
{
    isEnd = true;
}


bool
TrieNode::getEnd()
{
    return isEnd;
}


int
TrieNode::getLinks()
{
    int count = 0;
    for ( int i = 0; i < R; ++i )
    {
        if ( this->links[i] != nullptr )
        {
            count++;
        }
    }
    return count;
}


TrieNode::~TrieNode()
{
    for ( int i = 0; i < R; ++i )
    {
        if ( links[i] != nullptr )
        {
            delete links[i];
        }
    }
}


Trie::Trie()
{
    root = new TrieNode{};
}


/** Inserts a word into the trie. */
void
Trie::insert( std::string word )
{
    auto node = root;
    for ( auto &ch: word )
    {
        if ( !node->containsKey( ch ))
        {
            node->put( ch, new TrieNode{} );
        }
        node = node->get( ch );
    }
    node->setEnd();
}


/** Returns if the word is in the trie. */
bool
Trie::search( std::string word )
{
    auto node = searchPrefix( std::move( word ));
    return node != nullptr && node->getEnd();
}


/** Returns if there is any word in the trie that starts with the given prefix. */
bool
Trie::startsWith( std::string prefix )
{
    auto node = searchPrefix( std::move( prefix ));
    return node != nullptr;
}


std::string
Trie::longestCommonPrefix()
{
    std::string res = "";
    std::string chars = "abcdefghijklmnopqrstuvwxyz";
    auto node = root;
    while ( node->getLinks() == 1 && !node->getEnd())
    {
        for(auto & c: chars)
        {
            if (node->containsKey(c))
            {
                res += c;
                node = node->get(c);
                break;
            }
        }
    }
    return res;
}


Trie::~Trie()
{
    delete root;
}


// search a prefix or whole key in trie and
// returns the node where search ends
TrieNode *
Trie::
searchPrefix( std::string word )
{
    auto node = root;
    for ( auto &ch : word )
    {
        if ( node->containsKey( ch ))
        {
            node = node->get( ch );
        }
        else
        {
            TrieNode *tmp = nullptr;
            return tmp;
        }
    }
    return node;
}
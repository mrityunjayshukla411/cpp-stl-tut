#include <print>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string_view>
#include <memory>

using namespace std;

class Trie
{
private:
    struct TrieNode
    {
        unordered_map<char, unique_ptr<TrieNode>> children;
        bool isEnd = false;
    };

    unique_ptr<TrieNode> root;
    void printTrieHelper(TrieNode *node, string currentPath);

public:
    Trie();
    void insert(string_view word);
    bool search(string_view word);
    bool prefix(string_view word);
    void printTrie();
};

void Trie::insert(string_view word)
{
    TrieNode *Node = root.get();
    for (char ch : word)
    {
        if (Node->children.find(ch) == Node->children.end())
        {
            Node->children[ch] = make_unique<TrieNode>();
        }
        Node = Node->children[ch].get();
    }
    Node->isEnd = true;
}

bool Trie::search(string_view word)
{
    TrieNode *Node = root.get();
    for (char ch : word)
    {
        if (Node->children.find(ch) == Node->children.end())
        {
            return false;
        }
        Node = Node->children[ch].get();
    }
    return Node->isEnd;
}

bool Trie::prefix(string_view word)
{
    TrieNode *Node = root.get();
    for (char ch : word)
    {
        if (Node->children.find(ch) == Node->children.end())
        {
            return false;
        }
        Node = Node->children[ch].get();
    }
    return Node != nullptr;
}

void Trie::printTrie()
{
    return printTrieHelper(root.get(), "ROOT");
}

void Trie::printTrieHelper(TrieNode *node, string currentPath)
{
    if (node->isEnd)
    {
        println("{}", currentPath);
    }

    for (auto const &[ch, nextNode] : node->children)
    {
        printTrieHelper(nextNode.get(), currentPath + "->" + ch);
    }
}

Trie::Trie()
{
    root = make_unique<TrieNode>();
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        println("Usage: ./bin word1 word2 word3 word4 ...");
    }

    unique_ptr<Trie> tr = make_unique<Trie>();

    for (int i = 1; i < argc; i++)
    {
        tr->insert(argv[i]);
    }

    tr->printTrie();

    return 0;
}

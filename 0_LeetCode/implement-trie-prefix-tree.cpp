class TrieNode {
public:
    vector<TrieNode*> node_char;
    bool word_done;

    // Initialize your data structure here.
    TrieNode() :
        node_char(vector<TrieNode*>(26,nullptr)),
        word_done(false) {}
    
    ~TrieNode() {
        for (auto& node : node_char) {
            if (node != nullptr) delete node;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* ptr = root;
        for (auto c : word) {
            if (ptr->node_char[c-'a']==nullptr)
                ptr->node_char[c-'a'] = new TrieNode();
            ptr = ptr->node_char[c-'a'];
        }
        ptr->word_done = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* ptr = root;
        for (auto c : word) {
            if (ptr->node_char[c-'a']==nullptr) return false;
            ptr = ptr->node_char[c-'a'];
        }
        return ptr->word_done;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (auto c : prefix) {
            if (ptr->node_char[c-'a']==nullptr) return false;
            ptr = ptr->node_char[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
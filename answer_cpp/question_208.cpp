class Trie {
private:
    bool isEnd = false;
    Trie *next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (auto ch : word) {
            ch -= 'a';
            if (node->next[ch] == nullptr) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (auto ch : word) {
            node = node->next[ch - 'a'];
            if (node == nullptr) return false;
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto ch : prefix) {
            node = node->next[ch - 'a'];
            if (node == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 // prefix tree
 
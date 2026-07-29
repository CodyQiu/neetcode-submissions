class WordDictionary {
public:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool endOfWord;
        TrieNode(): children(), endOfWord(false) {}
    };
    WordDictionary() {
        root = new TrieNode();
    }
    TrieNode* root;
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (curr->children.contains(c)) curr = curr->children[c];
            else {
                TrieNode* temp = new TrieNode();
                curr->children[c] = temp;
                curr = temp;
            }
        }
        curr->endOfWord = true;
    }

    bool search(string word, TrieNode* head) {
        TrieNode* curr = head;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (auto& [a,b]: curr->children) {
                    bool temp = search(word.substr(i + 1),b);
                    if (temp) return true;
                }
                return false;
            } else if (curr->children.contains(word[i])) curr = curr->children[word[i]];
            else return false;
        }
        if (curr->endOfWord) return true;
        else return false;
    }


    bool search(string word) {
        return search(word, root);
    }
};

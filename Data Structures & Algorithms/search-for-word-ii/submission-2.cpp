class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> next;
        bool endOfWord;
        TrieNode(): next(26, nullptr), endOfWord(false) {}
    };
    bool inBounds(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size()) return false;
        if (y < 0 || y >= board[0].size()) return false;
        return true;
    }

    void recurse(vector<vector<char>>& board, TrieNode* root, unordered_set<int>& visited, unordered_set<string>& total, int x, int y, string& curr) {
        if (root->endOfWord) total.insert(curr);
        if (visited.contains(x * board[0].size() + y) || !inBounds(board, x, y)) return;
        else visited.insert(x * board[0].size() + y);
        if (root->next[board[x][y] - 'a'] == nullptr) {
            visited.erase(x * board[0].size() + y);
            return;
        }
        else root = root->next[board[x][y] - 'a'];
        curr.push_back(board[x][y]);
        recurse(board, root, visited, total, x + 1, y, curr);
        //visited.erase((x + 1) * board[0].size() + y);
        recurse(board, root, visited, total, x, y + 1, curr);
        //visited.erase(x * board[0].size() + y + 1);
        recurse(board, root, visited, total, x - 1, y, curr);
        //visited.erase((x - 1) * board[0].size() + y);
        recurse(board, root, visited, total, x, y - 1, curr);
        //visited.erase(x * board[0].size() + y - 1);

        visited.erase(x * board[0].size() + y);
        curr.pop_back();
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Create Trie
        TrieNode* root = new TrieNode();
        for (string word: words) {
            TrieNode* curr = root;
            for (char c: word) {
                if (curr->next[c - 'a'] == nullptr) {
                    TrieNode* temp = new TrieNode();
                    curr->next[c - 'a'] = temp;
                    curr = temp;
                } else {
                    curr = curr->next[c -  'a'];
                }
            }
            curr->endOfWord = true;
        }
        unordered_set<string> total;
        // Recurse
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                unordered_set<int> visited;
                string currr = "";
                recurse(board, root, visited, total, i, j, currr);
            }
        }
        vector<string> temp;
        for (string x: total) temp.push_back(x);
        return temp;
    }
};

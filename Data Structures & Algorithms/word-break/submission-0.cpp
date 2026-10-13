class Solution {
public:

    bool dfs(string s, vector<string>& wordDict, unordered_map<string, bool>& dp) {
        if (s.size() == 0) return true;
        if (dp.contains(s)) return dp[s];
        bool curr = false;
        for (string word: wordDict) {
            if (s.size() >= word.size() && s.substr(0, word.size()) == word) curr = dfs(s.substr(word.size()), wordDict, dp) || curr;
        }
        dp[s] = curr;
        return curr;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dp;
        bool final = dfs(s, wordDict, dp);
        return final;
    }
};

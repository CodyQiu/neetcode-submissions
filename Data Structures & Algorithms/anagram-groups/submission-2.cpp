class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> final;
        for (string s: strs) {
            vector<int> count(26, 0);
            for (char c: s) {
                count[c - 'a']++;
            }
            string temp = "";
            for (int i = 0; i < 26; i++) {
                temp = temp + "," + to_string(count[i]);
            }
            final[temp].push_back(s);
        }
        vector<vector<string>> returnment;
        for (auto& [one,two]: final) {
            returnment.push_back(two);
        }
        return returnment;
    }
};

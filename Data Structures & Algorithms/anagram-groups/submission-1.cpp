#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> final;
        for (string s: strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            bool within = false;
            for (vector<string>& v: final) {
                string sorted2 = v[0];
                sort(sorted2.begin(), sorted2.end());
                if (sorted == sorted2) {
                    v.push_back(s);
                    within = true;
                }
            }
            if (!within) {
                vector<string> newvec;
                newvec.push_back(s);
                final.push_back(newvec);
            }
        }
        return final;
    }
};

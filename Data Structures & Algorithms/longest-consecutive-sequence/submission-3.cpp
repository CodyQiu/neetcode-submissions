class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        unordered_map<int, unordered_set<int>> m1;
        unordered_map<int, int> m2;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i] - 1) != s.end()) {
                m1[nums[i]].insert(nums[i]);
                m2[nums[i]] = 1;
            }
        }
        int i = s.size();
        while (i >= 0) {
            for (auto& [key, value]: m1) {
                if (s.find(key + m2[key]) != s.end()) {
                    m2[key]++;
                } else {
                    continue;
                }
            }
            i--;
        }



        // for (int i = 0; i < nums.size(); i++) {
        //     if (s.find(nums[i] - 1) != s.end()) {
        //         for (auto& [key, value] : m1) {
        //             if (m1[key].find(nums[i]-1) != m1[key].end()) {
        //                 m1[key].insert(nums[i]);
        //                 m2[key]++;
        //             }
        //         }
        //     }
        // }
        int max = 0;
        for (auto& [key, value]: m2) {
            if (value > max) {
                max = value;
            }
        }
        return max + 1;
    }
};
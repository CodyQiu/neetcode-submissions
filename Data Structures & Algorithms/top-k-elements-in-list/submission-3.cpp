class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        vector<pair<int, int>> pairs;
        for (const auto& [one, two]: freq) {
            pairs.push_back({two, one});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> final;
        for (int i = 0; i < k; i++) {
            final.push_back(pairs[pairs.size() - 1 - i].second);
        }
        return final;
    }
};

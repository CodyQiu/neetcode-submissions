class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> final;
        vector<int> temp;
        map<int, int> freq;
        for (int i: nums) {
            freq[i]++;
        }
        // for (auto [key, value]: freq) {
        //     temp.push_back(value);
        // }
        int index = k;
        int keyy;
        int max = -1001;
        while (k > 0) {
            bool newele = false;
            for (auto [key,value]: freq) {
                if (value > max) {
                    keyy = key;
                    max = value;
                    newele = true;
                }
            }
            if (newele = true) {
                final.push_back(keyy);
                freq[keyy] = -1001;
                max = -1001;
                k--;
            }
        }
        return final;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cheating;
        for (int i: nums1) {
            cheating.push_back(i);
        }
        for (int i: nums2) {
            cheating.push_back(i);
        }
        sort(cheating.begin(), cheating.end());
        if (cheating.size() % 2 == 1) {
            return cheating[cheating.size()/2];
        } else {
            return (double)(cheating[cheating.size()/2] + cheating[cheating.size()/2-1])/2;
        }
    }
};

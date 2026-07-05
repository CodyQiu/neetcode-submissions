class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int half = (nums1.size() + nums2.size()) / 2;
        vector<int> A;
        vector<int> B;
        if (nums1.size() > nums2.size()) {
            A = nums2;
            B = nums1;
        }
        else {
            A = nums1;
            B = nums2;
        }
        if (A.size() == 0) {
            if (B.size() == 0) return 0;
            if (A.size() + B.size() % 2 != 0) return B[half];
            else return (B[half - 1] + B[half]) / 2.0;
        }
        int left = 0;
        int right = half;
        while (left <= right) {
            int split = (left + right) / 2;
            int split2 = half - split;
            int left1 = (split <= 0) ? INT_MIN : A[split - 1];
            int left2 = (split2 <= 0) ? INT_MIN : B[split2 - 1];
            int right1 = (split >= A.size()) ? INT_MAX : A[split];
            int right2 = (split2 >= B.size()) ? INT_MAX : B[split2];
            if (max(left1, left2) <= min(right1, right2)) {
                if ((nums1.size() + nums2.size()) % 2 == 0) return (double)(max(left1, left2) + min(right1, right2)) / 2;
                else {
                    return min(right1, right2);
                }
            } else if (left1 > right2) {
                right = split - 1;
            } else if (left2 > right1) {
                left = split + 1;
            }
        }
        return 69;
    }
};

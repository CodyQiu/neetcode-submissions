class Solution {
public:
    int compute(int k, vector<int>& piles) {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += ceil((double)piles[i] / k);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > max) max = piles[i];
        }
        while (max >= min) {
            int k = ceil((max + min)/2.0);
            int time = compute(k, piles);
            if (time <= h) {
                min = min;
                max = k - 1;
            } else {
                min = k + 1;
                max = max;
            }
        }
        if (compute(max, piles) <= h) {
            if (max > 0 ) return max;
            else return 1;
        }
        else {
            if (min > 0) return min;
            else return 1;
        }
    }
};
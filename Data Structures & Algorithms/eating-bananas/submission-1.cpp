class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int i: piles) right = max(right, i);
        int smallest = right;
        while (left <= right) {
            int center = (left + right) / 2;
            int time = 0;
            for (int i: piles) {
                if (i % center == 0) time += i / center;
                else time += i / center + 1;
            }
            if (time > h) {
                left = center + 1;
            } else {
                right = center - 1;
                smallest = min(smallest, center);
            }
        }
        return smallest;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int maxim = 0;
        for (int i = 1; i < prices.size(); i++) {
            minVal = min(minVal, prices[i-1]);
            maxim = max(maxim, prices[i] - minVal);
        }
        return maxim;
    }
};

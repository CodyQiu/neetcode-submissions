class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallLeft = prices[0];
        int final = 0;
        for (int i = 1; i < prices.size(); i++) {
            int temp = prices[i];
            prices[i] -= smallLeft;
            final = max(final, prices[i]);
            smallLeft = min(temp, smallLeft);
        }
        return final;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasT = 0;
        int costT = 0;
        for (int i = 0; i < gas.size(); i++) {
            gasT += gas[i];
            costT += cost[i];
        }
        if (gasT < costT) return -1;
        int best = 0;
        int currSum = gas[0];
        for (int i = 1; i < gas.size(); i++) {
            currSum -= cost[i - 1];
            if (currSum < 0) {
                best = i;
                currSum = 0;
            }
            currSum += gas[i];
        }
        return best;
    }
};

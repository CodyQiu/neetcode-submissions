class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int,int> freq;
        for (auto x: hand) {
            freq[x]++;
        }
        if (hand.size() % groupSize != 0) return false;
        int next = 0;
        while (next < hand.size()) {
            freq[hand[next]]--;
            for (int i = 0; i < groupSize - 1; i++) {
                if (freq[hand[next] + i + 1] > 0) {
                    freq[hand[next] + i + 1]--;
                } else return false;
            }
            while (next < hand.size() && freq[hand[next]] <= 0) {
                next++;
            }
        }
        return true;
    }
};

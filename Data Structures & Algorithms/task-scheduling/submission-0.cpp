class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c: tasks) freq[c]++;
        priority_queue<pair<int, char>> pq;
        queue<pair<int, char>> leftover;
        for (auto& [one, two]: freq) pq.push(pair(two, one));
        int rounds = 0;
        while (pq.size() > 0) {
            for (int i = 0; i < n + 1; i++) {
                if (pq.size() != 0) {
                    auto temp = pq.top();
                    temp.first--;
                    pq.pop();
                    if (temp.first > 0) leftover.push(temp);
                }
                rounds++;
                if (leftover.empty() && pq.empty()) return rounds;
            }
            while (leftover.size() > 0) {
                auto temp = leftover.front();
                leftover.pop();
                pq.push(temp);
            }
        }
        return rounds;
    }
};

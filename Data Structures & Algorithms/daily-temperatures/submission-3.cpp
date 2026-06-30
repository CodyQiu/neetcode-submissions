class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mono;
        vector<int> count(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (mono.size() == 0) {
                mono.push({temperatures[i], i});
                count[i] = 0;
            }
            else {
                while (mono.size() != 0 && temperatures[i] >= mono.top().first) {
                    mono.pop();
                }
                mono.push({temperatures[i], i});
            }
            // find count
            int first = mono.top().second;
            mono.pop();
            if (mono.size() == 0) {
                count[i] = 0;
                mono.push({temperatures[i],i});
                continue;
            }
            int second = mono.top().second;
            count[i] = second - first;
            mono.push({temperatures[i],i});
        }
        return count;
    }
};

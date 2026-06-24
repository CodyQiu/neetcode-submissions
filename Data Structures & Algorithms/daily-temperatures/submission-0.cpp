class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int arr[temperatures.size()];
        vector<int> v;
        stack<int> stk;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            if (stk.empty()) arr[i] = 0;
            else {
                while (temperatures[i] >= temperatures[stk.top()] && !stk.empty()) {
                    stk.pop();
                    if (stk.empty()) break;
                }
                if (stk.empty()) arr[i] = 0;
                else arr[i] = stk.top() - i;
            }
            stk.push(i);
        }
        for (int i: arr) v.push_back(i);
        return v;
    }
};

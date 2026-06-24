class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> stk;
        vector<pair<float, float>> vec;
        for (int i = 0; i < speed.size(); i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        for (auto& x: vec) {
            if (stk.empty()) stk.push((target - x.first)/x.second);
            else {
                if ((target - x.first)/x.second > stk.top()) {
                    stk.push((target - x.first)/x.second);
                }
            }
        }
        return stk.size();
    }
};

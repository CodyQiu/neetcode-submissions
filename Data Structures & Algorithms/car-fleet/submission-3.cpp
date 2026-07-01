class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> pairs;
        int fleets = speed.size();
        for (int i = 0; i < speed.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            pairs.push_back({position[i], time});
        }
        sort(pairs.begin(), pairs.end());
        stack<pair<int, double>> s;
        for (auto& x: pairs) s.push(x);
        while (s.size() > 1) {
            pair<int, double> one = s.top();
            s.pop();
            pair<int, double> two = s.top();
            if (one.second >= two.second) {
                fleets--;
                s.pop();
                s.push(one);
            }
        }
        return fleets;
    }
};

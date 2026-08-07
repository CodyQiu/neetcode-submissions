class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(auto& v: points) {
            double distance = sqrt(v[0] * v[0]+ v[1] * v[1]);
            pq.push(pair(distance, v));
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> final;
        while (pq.size() > 0) {
            vector<int> temp = pq.top().second;
            pq.pop();
            final.push_back(temp);
        }
        return final;
    }
};

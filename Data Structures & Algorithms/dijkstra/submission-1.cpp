class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, int> distance;
        unordered_map<int, vector<vector<int>>> graph;
        
        for (int i = 0; i < n; i++) distance[i] = INT_MAX;
        for (auto& x: edges) {
            graph[x[0]].push_back(x);
        }
        distance[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({distance[src], src});

        while (!minHeap.empty()) {
            auto x = minHeap.top();
            minHeap.pop();
            if (x.first > distance[x.second]) continue;
            
            for (auto& y: graph[x.second]) {
                int newDistance = y[2] + x.first;
                if (newDistance < distance[y[1]]) {
                    distance[y[1]] = newDistance;
                    minHeap.push({distance[y[1]], y[1]});
                }
            }
        }
        for (auto& [one,two]: distance) {
            if (two == INT_MAX) distance[one] = -1;
        }
        return distance;
    }
};

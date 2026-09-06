class Solution {
public:
    void dfs(int n, unordered_set<int>& visited, unordered_map<int,vector<int>>& adj, int curr, int prev) {
        if (visited.contains(curr)) return;
        visited.insert(curr);
        for (auto x: adj[curr]) {
            if (x == prev) continue;
            dfs(n, visited, adj, x, curr);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        unordered_map<int,vector<int>> adj;
        for (auto& x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                count++;
                dfs(n, visited, adj, i, i);
            }
        }
        return count;
    }
};

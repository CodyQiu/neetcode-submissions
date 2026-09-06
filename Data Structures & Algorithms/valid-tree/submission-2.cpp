class Solution {
public:
    void dfs(int n, int& count, unordered_set<int>& visited, unordered_map<int,vector<int>>& adj, int curr, int prev) {
        // if (count == n) return true;
        if (visited.contains(curr)) {
            count -= 10;
            return;
        }
        visited.insert(curr);
        count++;
        for (auto x: adj[curr]) {
            if (x == prev) continue;
            dfs(n, count, visited, adj, x, curr);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        unordered_map<int,vector<int>> adj;
        for (auto& x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int curr = 0;
        int count = 0;
        int prev = 0;
        dfs(n, count, visited, adj, curr, prev);
        return count == n;
    }
};

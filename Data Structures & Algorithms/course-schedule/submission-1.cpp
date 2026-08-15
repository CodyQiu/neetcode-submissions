class Solution {
public:

    bool recurse(int numCourses, vector<vector<int>>& prerequisites, unordered_set<int>& path, unordered_map<int, vector<int>>& prereqs, int curr, unordered_set<int>& safe) {
        if (path.contains(curr)) return false;
        if (safe.contains(curr)) return true;
        path.insert(curr);

        for (auto x: prereqs[curr]) {
            bool temp = recurse(numCourses, prerequisites, path, prereqs, x, safe);
            if (!temp) return false;
        }
        safe.insert(curr);
        path.erase(curr);
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> path;
        unordered_map<int, vector<int>> prereqs;
        unordered_set<int> safe;
        for (auto& x: prerequisites) {
            prereqs[x[0]].push_back(x[1]);
        }
        for (auto& [one,two]: prereqs) {
            bool temp = recurse(numCourses, prerequisites, path, prereqs, one, safe);
            if (!temp) return false;
        }
        return true;
    }
};

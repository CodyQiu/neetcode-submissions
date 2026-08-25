class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        queue<int> q;
        unordered_map<int,int> indegree;
        unordered_map<int,vector<int>> postreq;
        for (auto& x: prerequisites) {
            postreq[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (q.size() > 0) {
            auto temp = q.front();
            q.pop();
            order.push_back(temp);
            for (auto& course: postreq[temp]) {
                indegree[course]--;
                if (indegree[course] == 0) {
                    q.push(course);
                }
            }
        }
        if (order.size() != numCourses) return {};
        return order;
    }
};

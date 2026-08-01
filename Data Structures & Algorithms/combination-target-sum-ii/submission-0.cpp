class Solution {
public:

    void backTrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& total, int depth) {
        if (target == 0) {
            total.push_back(current);
            return;
        } else if (target < 0 || depth >= candidates.size()) {
            return;
        }
        //if (depth > 0 && candidates[depth - 1] == candidates[depth]) {
           // if (current.size() == 0) return;
         //   if (current[current.size() - 1] != candidates[depth]) return;
        //}
        current.push_back(candidates[depth]);
        backTrack(candidates, target - candidates[depth], current, total, depth + 1);
        current.pop_back();
        while (depth < candidates.size() - 1 && candidates[depth] == candidates[depth + 1]) depth++;
        backTrack(candidates, target, current, total, depth + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> total;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, current, total, 0);
        return total;
    }
};

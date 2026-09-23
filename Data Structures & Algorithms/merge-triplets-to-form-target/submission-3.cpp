class Solution {
public:

    // void helper(vector<string>& work, string& curr) {
    //     for (int i = 0; i < 3; i++) {

    //     }
    // }

    // bool helper2(vector<string>& work) {
    //     for (int i = 0; i < 3; i++) {
    //         for (int j = i + 1; j < 3; j++) {
    //             string temp = "000";
    //             for (int k = 0; k < 3; k++) {
    //                 if (work[i][k] == '1' || work[j][k] == '1') temp[k] = '1';
    //             }
    //             if (temp == "111") return true;
    //         }
    //     }
    //     return false;
    // }

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //vector<string> work = {"000", "000", "000"};
        vector<vector<int>> triple;
        for (auto& x: triplets) {
            if (x[0] <= target[0] && x[1] <= target[1] && x[2] <= target[2]) {
                triple.push_back(x);
            }
        }
        string final = "000";
        for (auto x: triple) {
            string curr = "000";
            if (x[0] == target[0]) curr[0] = '1';
            if (x[1] == target[1]) curr[1] = '1';
            if (x[2] == target[2]) curr[2] = '1';

            for (int i = 0; i < 3; i++) {
                if (curr[i] == '1') final[i] = '1';
            }
            if (final == "111") return true;
            //helper(work, curr);
            //if (helper2(work)) return true;
        }
        return false;
    }
};

class Solution {
public:

    bool dfs(vector<vector<vector<int>>>& dp, string s1, string s2, string s3, int p1, int p2, int p3, int m, int n, int curr) {
        if (p3 >= s3.size() && p2 >= s2.size() && p1 >= s1.size()) {
            return abs(m - n) <= 1;
        }
        if (s1[p1] != s3[p3] && s2[p2] != s3[p3]) return false;
        if (p1 < s1.size() && p2 < s2.size() && dp[p1][p2][curr] != -1) return dp[p1][p2][curr];
        int temp = false;
        if (curr == 0) {
            if (p1 < s1.size() && s1[p1] == s3[p3]) temp = temp || dfs(dp, s1,s2,s3, p1 + 1, p2, p3 + 1, m + 1,n, 1);
            if (p2 < s2.size() && s2[p2] == s3[p3]) temp = temp || dfs(dp,s1,s2,s3, p1, p2 + 1, p3 + 1, m, n + 1, 2);
        }
        else if (curr == 1) {
            if (p1 < s1.size() && s1[p1] == s3[p3]) temp = temp || dfs(dp,s1,s2,s3, p1 + 1, p2, p3 + 1, m, n, 1);
            if (p2 < s2.size() && s2[p2] == s3[p3]) temp = temp || dfs(dp,s1,s2,s3, p1, p2 + 1, p3 + 1, m, n + 1, 2);
        }
        else if (curr == 2) {
            if (p1 < s1.size() && s1[p1] == s3[p3]) temp = temp || dfs(dp,s1,s2,s3, p1 + 1, p2, p3 + 1, m + 1, n, 1);
            if (p2 < s2.size() && s2[p2] == s3[p3]) temp = temp || dfs(dp,s1,s2,s3, p1, p2 + 1, p3 + 1, m, n, 2);
        }
        dp[p1][p2][curr] = temp;
        return temp;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = 0;
        int n = 0;
        vector<vector<vector<int>>> dp = vector(s1.size() + 1, vector(s2.size() + 1, vector(3, -1)));
        bool final = dfs(dp,s1, s2, s3, 0, 0, 0, m, n, 0);
        if (m - n > 1 || n - m > 1) return false;
        else return final;
    }
};

class Solution {
public:
    struct Interval {
        char ch;
        int left = -1;
        int right = -1;
    };
    vector<int> partitionLabels(string s) {
        unordered_map<char, Interval> m;
        vector<int> final;
        for (int i = 0; i < s.size(); i++) {
            if (!m.contains(s[i])) {
                Interval temp;
                temp.ch = s[i];
                temp.left = i;
                temp.right = i;
                m[s[i]] = temp;
            } else {
                auto& temp = m[s[i]];
                temp.right = i;
            }
        }
        int start = 0;
        int end = m[s[0]].right;
        int i = 0;
        char curr = s[0];
        while (i < s.size()) {
            curr = s[i];
            end = m[curr].right;
            while (i <= end) {
                if (s[i] != curr) {
                    end = max(m[s[i]].right, m[curr].right);
                    if (m[s[i]].right > m[curr].right) curr = s[i];
                }
                i++;
            }
            final.push_back(end - start + 1);
            start = end + 1;
        }
        return final;
    }
};

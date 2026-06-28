class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping;
        mapping[')'] = '(';
        mapping[']'] = '[';
        mapping['}'] = '{';
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else if (mapping.contains(c)) {
                if (st.size() != 0 && mapping[c] == st.top()) st.pop();
                else return false;
            }
        }

        if (st.size() == 0) return true;
        else return false;
    }
};

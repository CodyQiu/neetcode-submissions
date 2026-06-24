class Solution {
public:

    string encode(vector<string>& strs) {
        string final = "";
        for (string s: strs) {
            final += s;
            final += "|";
        }
        return final;
    }

    vector<string> decode(string s) {
        vector<string> final;
        int start = 0;
        int size = 0;
        for (char c: s) {
            if (c == '|') {
                final.push_back(s.substr(start, size));
                start += size + 1;
                size = 0;
            } else {
                size++;
            }
        }
        return final;
    }
};

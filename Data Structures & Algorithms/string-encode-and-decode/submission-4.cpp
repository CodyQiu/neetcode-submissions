class Solution {
public:

    string encode(vector<string>& strs) {
        string final = "";
        for (int i = 0; i < strs.size(); i++) {
            int length = strs[i].size();
            final += to_string(length) + "#";
            final += strs[i];
        }
        return final;
    }

    vector<string> decode(string s) {
        if (s == "") return {};
        int counter = 0;
        vector<string> strs;
        while (counter < s.size()) {
            string strword = "";
            while (s[counter] != '#') {
                strword += s[counter];
                counter++;
            }
            int wordlength = stoi(strword);
            string word = s.substr(counter + 1, wordlength);
            counter += wordlength + 1;
            strs.push_back(word);
        }
        return strs;
    }
};

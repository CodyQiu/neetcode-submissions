class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string, int> p1 = {value, timestamp};
        m[key].push_back(p1);
    }
    
    string get(string key, int timestamp) {
        for (auto& p: m[key]) {
            if (p.second == timestamp) return p.first;
        }
        vector<pair<string, int>> v = m[key];
        reverse(v.begin(), v.end());
        for (auto& p: v) {
            if (p.second < timestamp) return p.first;
        }
        return "";
    }
};

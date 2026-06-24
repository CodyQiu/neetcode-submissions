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
        vector<pair<string, int>> v = m[key];
        int l = 0;
        int r = v.size() - 1;
        string result = "";
        while (r >= l) {
            int mid = (l+r)/2;
            // if (v[mid].second == timestamp) return v[mid].first;
            if (v[mid].second <= timestamp) {
                result = v[mid].first;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // if (v[l].second < timestamp) return v[l].first;
        // else if (v[r].second < timestamp) return v[r].first;
        // return "";
        return result;
    }
};

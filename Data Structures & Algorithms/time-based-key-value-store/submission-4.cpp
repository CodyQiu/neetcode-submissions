class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> maps;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        maps[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = maps[key].size() - 1;
        int maxTemp = -1;
        while (left <= right) {
            int center = (left + right) / 2;
            if (maps[key][center].first <= timestamp) {
                left = center + 1;
                maxTemp = max(maxTemp, center);
            } else {
                right = center - 1;
            }
        }
        if (maxTemp == -1) return "";
        return maps[key][maxTemp].second;
    }
};

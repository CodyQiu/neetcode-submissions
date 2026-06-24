#include <set>
using namespace std;


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i: nums) {
            if (s.count(i) == 1) return true;
            else {
                s.insert(i);
            }
        }
        return false;
    }
};
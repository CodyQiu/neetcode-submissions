class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i: stones) pq.push(i);

        while (pq.size() > 1) {
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if (temp1 > temp2) pq.push(temp1 - temp2);
        }
        if (pq.size() > 0) return pq.top();
        else return 0;
    }
};

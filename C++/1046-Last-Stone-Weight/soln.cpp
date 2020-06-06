class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a > b) swap(a, b);
            if (a != b) pq.push(b - a);
        }
        if (pq.size() == 1) return pq.top();
        return 0;
    }
};

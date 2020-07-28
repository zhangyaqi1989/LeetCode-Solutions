class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pool(sticks.begin(), sticks.end());
        int ans = 0;
        while(pool.size() > 1) {
            int x = pool.top();
            pool.pop();
            int y = pool.top();
            pool.pop();
            ans += x + y;
            pool.push(x + y);
        }
        return ans;
    }
};

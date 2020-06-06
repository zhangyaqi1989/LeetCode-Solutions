class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        int idx = 0;
        while (N > 1) {
            --N;
            if (idx == 2) {
                stk.push(N);
            } else if (idx == 3) {
                stk.push(-N);
            } else if (idx == 0) {
                int top = stk.top();
                stk.pop();
                stk.push(top * N);
            } else {
                int top = stk.top();
                stk.pop();
                if (top >= 0) stk.push(top / N);
                else stk.push(-((-top) / N));
            }
            
            idx = (idx + 1) % 4;
            
        }
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

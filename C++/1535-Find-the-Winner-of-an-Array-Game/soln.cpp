class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k >= arr.size()) return *max_element(arr.begin(), arr.end());
        deque<int> dq{arr.begin(), arr.end()};
        int val = -1, cnt = 0;
        while(true) {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if(a < b) swap(a, b);
            if(val != a) {
                val = a;
                cnt = 1;
            } else {
                ++cnt;
            }
            dq.push_back(b);
            dq.push_front(a);
            if(cnt >= k) return val;
        }
        return -1;
    }
};

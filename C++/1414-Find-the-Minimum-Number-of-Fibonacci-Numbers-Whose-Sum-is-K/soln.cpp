class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibs = {1, 1};
        int a = 1, b = 1;
        while (b <= k) {
            int c = a + b;
            a = b;
            b = c;
            fibs.push_back(b);
        }
        int cnt = 0;
        while(k != 0) {
            ++cnt;
            auto it = lower_bound(fibs.begin(), fibs.end(), k);
            if (*it > k) k -= *(prev(it));
            else k = 0;
        }
        return cnt;
    }
};

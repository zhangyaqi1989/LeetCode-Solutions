class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0;
        int counter [256] = {0};
        for(char ch : tasks) {
            if (++counter[ch + 128] > mx) {
                mx = counter[ch + 128];
            }
        }
        int mx_count = 0;
        for(int i = 0; i < 256; ++i) mx_count += counter[i] == mx;
        return max(static_cast<int>(tasks.size()), (n + 1) * (mx - 1) + mx_count);
    }
};

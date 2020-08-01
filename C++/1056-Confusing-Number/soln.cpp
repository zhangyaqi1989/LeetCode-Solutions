class Solution {
public:
    bool confusingNumber(int N) {
        string N_str = to_string(N);
        int m[] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int ans = 0;
        for(auto it = N_str.rbegin(); it != N_str.rend(); ++it) {
            int d = (*it) - '0';
            int rd = m[d];
            if(rd == -1) return false;
            ans = ans * 10 + rd;
        }
        return ans != N;
    }
};

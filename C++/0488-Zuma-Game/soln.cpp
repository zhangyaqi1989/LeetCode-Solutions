class Solution {
public:
    int findMinStep(string board, string hand) {
        map<char, int> counter;
        for(char ch : hand) {
            ++counter[ch];
        }
        board += "#";
        int ans = helper(board, counter);
        return ans > hand.size() ? -1 : ans;
    }
    
    int helper(string board, map<char, int> & counter) {
        int n = board.length();
        if (n == 1) return 0;
        int ans = 10;
        int lo = 0;
        for(int hi = 0; hi < n; ++hi) {
            if (board[hi] != board[lo]) {
                int need = max(0, 3 - (hi - lo));
                if (counter[board[lo]] >= need) {
                    counter[board[lo]] -= need;
                    int temp = helper(board.substr(0, lo) + board.substr(hi), counter);
                    counter[board[lo]] += need;
                    ans = min(ans, temp + need);
                }
                lo = hi;
            }
        }
        return ans;
    }
};

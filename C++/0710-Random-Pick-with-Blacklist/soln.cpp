class Solution {
    int M;
    unordered_map<int, int> blackmap;
    
public:
    Solution(int N, vector<int> blacklist) {
        sort(blacklist.begin(), blacklist.end());
        M = N - blacklist.size();
        unordered_set<int> blackset(blacklist.begin(), blacklist.end());
        int num = M;
        int idx = 0;
        while (num < N) {
            if (blackset.find(num) == blackset.end()) {
                blackmap[blacklist[idx++]] = num;
            }
            ++num;
        }
    }
    
    int pick() {
        int idx = rand() % M;
        if (blackmap.find(idx) != blackmap.end()) {
            return blackmap[idx];
        }
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

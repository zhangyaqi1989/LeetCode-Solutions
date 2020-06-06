class Solution {
    vector<int> ws;
    int upper;
    
public:
    Solution(vector<int> w) {
        ws = w;
        int n = ws.size();
        for(int i = 1; i < n; ++i) ws[i] += ws[i - 1];
        upper = ws.back();
    }
    
    int pickIndex() {
        int num = rand() % upper + 1;
        return lower_bound(ws.begin(), ws.end(), num) - ws.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

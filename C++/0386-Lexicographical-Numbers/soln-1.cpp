class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        Helper(1, n, & ans);
        return ans;
    }
    
private:
    void Helper(int cur, int n, vector<int> * ans) {
        if(cur > n) return;
        ans->push_back(cur);
        Helper(cur * 10, n, ans);
        if(cur % 10 != 9) Helper(cur + 1, n, ans);
    }
};

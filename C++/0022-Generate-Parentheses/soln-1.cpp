class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string combi;
        dfs(ans, combi, n, n);
        return ans;
    }
    
private:
    void dfs(vector<string> & ans, string & combi, int lefts, int rights) {
        if (lefts > rights || lefts < 0 || rights < 0) return;
        if (lefts == 0 && rights == 0) {
            ans.push_back(combi);
        } else {
            combi += '(';
            dfs(ans, combi, lefts - 1, rights);
            combi.pop_back();
            combi += ')';
            dfs(ans, combi, lefts, rights - 1);
            combi.pop_back();
        }
    }
};

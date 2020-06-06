class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string cand;
        dfs(cand, n, ans);
        if(ans.size() < k) return "";
        else {
            sort(ans.begin(), ans.end());
            return ans[k - 1];
        }
    }
    
private:
    void dfs(string cand, int n, vector<string> & ans) {
        if (cand.length() == n) ans.push_back(cand);
        else {
            for(char nxt : {'a', 'b', 'c'}) {
                if(!cand.empty() && cand.back() == nxt) continue;
                cand += nxt;
                dfs(cand, n, ans);
                cand.pop_back();
            }
        }
    }
};

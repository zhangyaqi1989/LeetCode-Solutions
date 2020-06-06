class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> memo(target + 1, "-");
        return dp(target, cost, &memo);
    }
    
private:
    
    bool greater(string cand, string ans) {
        if(cand.length() == ans.length()) return cand > ans;
        else return cand.length() > ans.length();
    }
    
    string dp(int target, const vector<int> & cost, vector<string> * memo) {
        if(target == 0) return "";
        if((*memo)[target] != "-") return (*memo)[target];
        string ans = "0";
        for(int i = 0; i < 9; ++i) {
            if(target >= cost[i]) {
                string cand = to_string(i + 1) + dp(target - cost[i], cost, memo);
                if(cand.back() != '0' && greater(cand, ans)) ans = cand;
            }
        }
        (*memo)[target] = ans;
        return ans;
    }
    
};

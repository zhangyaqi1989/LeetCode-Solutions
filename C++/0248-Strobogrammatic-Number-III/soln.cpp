class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int mn = low.length(), mx = high.length();
        unordered_set<string> cands;
        for(int i = mn; i <= mx; ++i) {
            generate(i, cands, low, high);
        }
        return cands.size();
    }
    
    void generate(int n, unordered_set<string> & cands, string & low, string & high) {
        vector<string> ans;
        if (n % 2 == 1) {
            ans.push_back("0");
            ans.push_back("1");
            ans.push_back("8");
        } else {
            ans.push_back("");
        }
        vector<string> pairs = {"00", "11", "88", "69", "96"};
        while (n > 1) {
            int start = n - 2 > 1 ? 0 : 1;
            vector<string> temp;
            for(auto item : ans) {
                for(int i = start; i < 5; ++i) {
                    string p = pairs[i];
                    temp.push_back(p[0] + item + p[1]);
                }
            }
            swap(ans, temp);
            n -= 2;
        }
        for(auto item : ans) {
            if (check(item, low, high)) cands.insert(item);
        }
    }
    
    bool check(const string & num, const string & low, const string & high) {
        int n = num.length(), mn = low.length(), mx = high.length();
        if (n < mn || n > mx) return false;
        return (n > mn || num >= low) && (n < mx || num <= high);
    }
};

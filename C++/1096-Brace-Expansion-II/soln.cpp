class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        // cout << expression << endl;
        vector<vector<vector<string>>> st;
        st.push_back({});
        int start = 0;
        int level = 0;
        const int n = expression.size();
        for(int i = 0; i < n; ++i) {
            char ch = expression[i];
            if (ch == '{') {
                if (level++ == 0) {
                    start = i + 1;
                }
            } else if (ch == '}') {
                if(--level == 0) {
                    st.back().push_back(braceExpansionII(expression.substr(start, i - start)));
                }
            } else if (ch == ',' && level == 0) {
                st.push_back({});
            } else if (level == 0) {
                st.back().push_back({string(1, ch)});
            }
        }
        unordered_set<string> ans;
        
        for(auto & vv : st) {
            vector<string> g = {""};
            for(auto & v : vv) {
                vector<string> nxt_g;
                for(auto s : v) {
                    for(auto item : g) {
                        nxt_g.push_back(item + s);
                    }
                }
                swap(g, nxt_g);
            }
            for(auto s : g) {
                ans.insert(s);
            }
        }
        vector<string> res(ans.begin(), ans.end());
        sort(res.begin(), res.end());
        // for(string s : res) {
        //     cout << s << " ";
        // }
        // cout << endl;
        return res;
    }
};

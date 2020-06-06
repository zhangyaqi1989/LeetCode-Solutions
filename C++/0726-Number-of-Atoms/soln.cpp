ass Solution {
public:
    string countOfAtoms(string formula) {
        // stack of vector of pair<string, cnt>
        stack<vector<pair<string, long long>>> st;
        st.push({});
        const int n = formula.length();
        for(int i = 0; i < n; ++i) {
            if (formula[i] == '(') {
                st.push({});
            } else if (formula[i] == ')') {
                long long num = 0;
                ++i;
                while(i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i++] - '0');
                }
                --i;
                if (num == 0) num = 1;
                for(auto & p : st.top()) {
                    p.second *= num;
                }
                unordered_map<string, long long> counter;
                assert(st.size() >= 2);
                auto t1 = st.top();
                st.pop();
                auto t2 = st.top();
                st.pop();
                for(const auto & p : t1) {
                    counter[p.first] += p.second;
                }
                for(const auto & p : t2) {
                    counter[p.first] += p.second;
                }
                st.push({});
                for(auto & p : counter) {
                    st.top().push_back({p.first, p.second});
                } 
            } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
                string ele = string(1, formula[i]);
                ++i;
                while (i < n && formula[i] >= 'a' && formula[i] <= 'z') {
                    ele += formula[i++];
                }
                --i;
                st.top().push_back({ele, 1});
            } else {
                long long num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i++] - '0');
                }
                --i;
                st.top().back().second = num;
            }
        }
        auto t = st.top();
        st.pop();
        string ans = "";
        map<string, long long> temp;
        for(auto & p : t) temp[p.first] += p.second;
        for(auto & p : temp) {
            ans += p.first + (p.second > 1 ? to_string(p.second) : "");
        }
        return ans;
    }
};

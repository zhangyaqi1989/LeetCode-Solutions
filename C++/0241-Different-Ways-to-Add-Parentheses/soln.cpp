class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return helper(input, 0, input.length());
    }
    
    vector<int> helper(string & input, int i, int j) {
        bool isdigit = true;
        for(int idx = i; idx < j; ++idx) {
            char ch = input[idx];
            if (! ('0' <= ch && ch <= '9')) {
                isdigit = false;
                break;
            }
        }
        if (isdigit) {
            return {stoi(input.substr(i, j - i))};
        }
        vector<int> ans;
        for(int idx = i; idx < j; ++idx) {
            char ch = input[idx];
            if (! ('0' <= ch && ch <= '9')) {
                // cout << ch << endl;
                auto lefts = helper(input, i, idx);
                auto rights = helper(input, idx + 1, j);
                for(auto left : lefts) {
                    for(auto right : rights) {
                        // cout << left << " " << right << endl;
                        ans.push_back(func(ch, left, right));
                    }
                }
            }
        }
        return ans;
        
    }
    
    int func(char op, int l, int r) {
        if (op == '+') return l + r;
        else if (op == '-') return l - r;
        else return l * r;
    }
};

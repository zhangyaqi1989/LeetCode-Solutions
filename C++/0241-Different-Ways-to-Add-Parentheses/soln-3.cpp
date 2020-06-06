class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        const int n = input.length();
        return helper(input, 0, n);
    }
    
private:
    vector<int> helper(const string & input, int lo, int hi) {
        int code = lo * input.size() + hi;
        auto it = memo_.find(code);
        if (it != memo_.end()) {
            return it->second;
        }
        int num = 0;
        int i;
        for(i = lo; i < hi; ++i) {
            if (isdigit(input[i])) num = num * 10 + (input[i] - '0');
            else break;
        }
        if (i == hi) return {num};
        else {
            vector<int> ans;
            for(int j = i; j < hi; ++j) {
                if (!isdigit(input[j])) {
                    vector<int> lefts = helper(input, lo, j);
                    vector<int> rights = helper(input, j + 1, hi);
                    for(int l : lefts) {
                        for(int r : rights) {
                            switch(input[j]) {
                                case '+': ans.push_back(l + r); break;
                                case '-': ans.push_back(l - r); break;
                                case '*': ans.push_back(l * r); break;
                            }
                        }
                    }
                }
            }
            memo_.insert({code, ans});
            return ans;
        }
    }
    
unordered_map<int, vector<int>> memo_;
    
};

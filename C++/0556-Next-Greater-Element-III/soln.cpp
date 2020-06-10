class Solution {
public:
    int nextGreaterElement(int n) {
        string ans = to_string(n);
        next_permutation(ans.begin(), ans.end());
        long long nxt = stoll(ans);
        return (nxt > INT_MAX || nxt <= n) ? -1 : nxt;
    }
};

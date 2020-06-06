class Solution {
public:
    string generateTheString(int n) {
        string ans = string(n, 'a');
        if(n % 2 == 0) ans.back() = 'b';
        return ans;
    }
};

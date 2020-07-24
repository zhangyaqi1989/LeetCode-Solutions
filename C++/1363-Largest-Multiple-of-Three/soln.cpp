class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int m1 [] = {1, 4, 7, 2, 5, 8};
        int m2 [] = {2, 5, 8, 1, 4, 7};
        int counter[10] = {0};
        int sum = 0;
        for(int d : digits) {
            sum += d;
            ++counter[d];
        }
        while(sum % 3 != 0) {
            for(int d : (sum % 3 == 1 ? m1 : m2)) {
                if(counter[d]) {
                    --counter[d];
                    sum -= d;
                    break;
                }
            }
        }
        string ans;
        for(int d = 9; d >= 0; --d) {
            ans += string(counter[d], '0' + d);
        }
        if(ans.empty()) return "";
        return ans[0] == '0' ? "0" : ans;
    }
};

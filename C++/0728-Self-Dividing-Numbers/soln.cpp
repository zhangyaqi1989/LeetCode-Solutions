class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int num = left; num <= right; ++num) {
            if (isSelfDivid(num)) ans.push_back(num);
        }
        return ans;
    }
    
    bool isSelfDivid(int num) {
        int n = num;
        while (num > 0) {
            int d = num % 10;
            if (d == 0 || n % d != 0) return false;
            num /= 10;
        }
        return true;
    }
};

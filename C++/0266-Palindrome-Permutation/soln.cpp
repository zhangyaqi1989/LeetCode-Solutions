class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<int, int> counter;
        for(char ch : s) ++counter[ch];
        int cnt = 0;
        for(auto & p : counter) {
            int num = p.second;
            if (num & 1 == 1) {
                ++cnt;
                if (cnt > 1) return false;
            }
        }
        return true;
    }
};

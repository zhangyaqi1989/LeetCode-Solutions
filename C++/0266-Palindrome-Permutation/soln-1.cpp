class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> pool;
        for(auto ch : s) {
            if (pool.find(ch) == pool.end()) {
                pool.insert(ch);
            } else {
                pool.erase(ch);
            }
        }
        return pool.size() == 1 || pool.size() == 0;
    }
};

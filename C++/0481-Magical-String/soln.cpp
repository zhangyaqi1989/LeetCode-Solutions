class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2; 
        while (s.size() < n) {
            char cnt = s[i++] - '0';
            s += string(cnt, i & 1 == 1 ? '1' : '2');
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};

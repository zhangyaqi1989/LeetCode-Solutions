class Solution {
public:
    bool checkInclusion(string s2, string s1) {
        int n1 = s1.length(), n2 = s2.length();
        vector<int> chars(26, 0);
        for(char ch : s2) ++chars[ch - 'a'];
        for(int i = 0; i < n1; ++i) {
            --chars[s1[i] - 'a'];
            if(i - n2 >= 0) ++chars[s1[i - n2] - 'a'];
            if(i >= n2 - 1 && all_of(chars.begin(), chars.end(), [](int x) {return x == 0;})){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool mapEqual(map<char, int> const & lhs, map<char, int> const & rhs) {
        return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        map<char, int> m1, m2;
        for(int i = 0; i < n1; ++i) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if (mapEqual(m1, m2)) return true;
        for(int i = 0; i < n2 - n1; ++i) {
            if (--m2[s2[i]] == 0) m2.erase(s2[i]);
            m2[s2[i + n1]]++;
            if (mapEqual(m1, m2)) return true;
        }
        return false;
    }
};

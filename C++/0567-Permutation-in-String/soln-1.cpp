class Solution {
public:
    bool arrayEqual(int m1[], int m2[], int n) {
        return equal(m1, m1 + n, m2);
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        int m1[26] = {0};
        int m2[26] = {0};
        for(int i = 0; i < n1; ++i) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }
        if (arrayEqual(m1, m2, 26)) return true;
        for(int i = 0; i < n2 - n1; ++i) {
            m2[s2[i] - 'a']--;
            m2[s2[i + n1] - 'a']++;
            if (arrayEqual(m1, m2, 26)) return true;
        }
        return false;
    }
};

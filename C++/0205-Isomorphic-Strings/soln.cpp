class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s.size(); i++)
        {
            auto it1 = m1.find(s[i]);
            if (it1 == m1.end())
                m1[s[i]] = t[i];
            else
            {
                if (it1->second != t[i])
                    return false;
            }
            auto it2 = m2.find(t[i]);
            if (it2 == m2.end())
                m2[t[i]] = s[i];
            else
            {
                if (it2->second != s[i])
                    return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int kN = s.length();
        vector<int> m_s(256, -1), m_t(256, -1);
        int cnt_s = 0, cnt_t = 0;
        for(int i = 0; i < kN; ++i) {
            int idx_s = s[i] + 128, idx_t = t[i] + 128;
            int vs = -1, vt = -1;
            if (m_s[idx_s] == -1) {
                m_s[idx_s] = cnt_s++;
            }
            if (m_t[idx_t] == -1) {
                m_t[idx_t] = cnt_t++;
            }
            if (m_s[idx_s] != m_t[idx_t]) return false;
        }
        return true;
    }
};

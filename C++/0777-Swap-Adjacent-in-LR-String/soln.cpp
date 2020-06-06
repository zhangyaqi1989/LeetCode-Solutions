class Solution {
public:
    bool canTransform(string start, string end) {
        // The relative order of L and R can not change
        int n = start.length();
        map<char, int> m_start, m_end;
        for(int i = 0; i < n; ++i) {
            if (start[i] != 'X') m_start[start[i]]++;
            if (end[i] != 'X') m_end[end[i]]++;
            if (m_start['R'] >= m_end['R'] && m_start['L'] <= m_end['L'] ) continue;
            else
                return false;
        }
        int i = 0, j = 0;
        while (i < n || j < n) {
            while(i < n && start[i] == 'X') {
                ++i;
            }
            while(j < n && end[j] == 'X') {
                ++j;
            }
            if (i == n || j == n) break;
            if (start[i] != end[j]) return false;
            ++i;
            ++j;
        }
        return i == n && j == n;
        
    }
};

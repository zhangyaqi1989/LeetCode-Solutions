class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left_shift = 0;
        for(const auto & p : shift) {
            int d = p[0], v = p[1];
            if(d == 0) left_shift += v;
            else left_shift -= v;
        }
        const int kN = s.length();
        left_shift %= kN;
        if(left_shift < 0) left_shift += kN;
        return s.substr(left_shift) + s.substr(0, left_shift);
    }
};

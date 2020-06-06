class Solution {
public:
    bool checkRecord(string s) {
        return count(s.begin(), s.end(), 'A') <= 1 && s.find("LLL") == string::npos;
    }
};

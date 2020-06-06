class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        istringstream iss(s);
        string token;
        while (iss >> token) {
            ++cnt;
        }
        return cnt;
    }
};

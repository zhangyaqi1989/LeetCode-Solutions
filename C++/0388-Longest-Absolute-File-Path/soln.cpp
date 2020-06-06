class Solution {
public:
    int lengthLongestPath(string input) {
        string line;
        stringstream ss(input);
        int ans = 0;
        map<int, int> m;
        m[0] = 0;
        while (getline(ss, line, '\n')) {
            int depth = 0;
            int i = 0;
            while (i < line.length() && line[i] == '\t') {
                ++depth;
                ++i;
            }
            line = line.substr(depth);
            if (line.find(".") == string::npos) {
                m[depth + 1] = m[depth] + line.length() + 1;
            } else {
                int temp = m[depth] + line.length();
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

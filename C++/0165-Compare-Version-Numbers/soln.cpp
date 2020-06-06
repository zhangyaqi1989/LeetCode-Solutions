class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
        int v1 = 0, v2 = 0;
        while (i < n1 || j < n2) {
            if (i < n1) {
                auto newi = version1.find('.', i);
                if (newi == string::npos) {
                    v1 = stoi(version1.substr(i));
                    i = n1;
                } else {
                    v1 = stoi(version1.substr(i, newi - i));
                    i = newi + 1;
                }
            } else {
                v1 = 0;
            }
            if (j < n2) {
                auto newj = version2.find('.', j);
                if (newj == string::npos) {
                    v2 = stoi(version2.substr(j));
                    j = n2;
                } else {
                    v2 = stoi(version2.substr(j, newj - j));
                    j = newj + 1;
                }
            } else {
                v2 = 0;
            }
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
        }
        return 0;
    }
};

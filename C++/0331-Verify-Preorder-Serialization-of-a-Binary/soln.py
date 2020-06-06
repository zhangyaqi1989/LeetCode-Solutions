class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i = 0, n = preorder.length(), nslots = 1;
        while (i < n) {
            int j = preorder.find(',', i);
            string token = preorder.substr(i, j - i);
            if (token == "#") {
                if (--nslots < 0) return false;
            } else {
                if (nslots <= 0) return false;
                ++nslots;
            }
            i = j + 1;
            if (j == string::npos) break;
        }
        return nslots == 0;
    }
};

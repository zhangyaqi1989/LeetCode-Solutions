class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int cnt = 0;
        for(int i = 0; i < n; i += 2) {
            if (abs(row[i] - row[i + 1]) != 1 || min(row[i], row[i + 1]) % 2 == 1) {
                ++cnt;
                for (int j = i + 2; j < n; ++j) {
                    if(abs(row[i] - row[j]) == 1 && min(row[i], row[j]) % 2 == 0) {
                        swap(row[j], row[i + 1]);
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};

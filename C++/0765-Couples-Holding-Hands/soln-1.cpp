class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        // find and switch
        const int N = row.size();
        int cnt = 0;
        for(int i = 0; i < N; i += 2) {
            if (abs(row[i] - row[i + 1]) == 1 && min(row[i], row[i + 1]) % 2 == 0) continue;
            for(int j = i + 2; j < N; ++j) {
                if (abs(row[i] - row[j]) == 1 && min(row[i], row[j]) % 2 == 0) {
                    swap(row[i + 1], row[j]);
                    ++cnt;
                    break;
                }
            }
        }
        // for(int num : row) {
        //     cout << num << " ";
        // }
        // cout << endl;
        return cnt;
    }
};

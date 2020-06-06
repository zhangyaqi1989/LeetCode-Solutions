class Solution {
public:
    int confusingNumberII(int num) {
        // rotated 180, becomes a different number
        // less than N + 1
        // numbers composed of 0 1 6 8 9
        // - rotated to be same number
        ++num;
        string str_num = to_string(num);
        const int kWidth = to_string(num).length();
        int ans = 0;
        // width < kWidth
        for(int w = 1; w < kWidth; ++w) {
            if (w == 1) {
                ans += 5;
            } else {
                int temp = 4;
                for(int j = 0; j < w - 1; ++j) temp *= 5;
                ans += temp;
            }
        }
        // width = kWidth
        vector<int> ds = {0, 1, 6, 8, 9};
        for(int i = 0; i < kWidth; ++i) {
            int d = str_num[i] - '0';
            int start = (i == 0 && kWidth > 1) ? 1 : 0; // remember
            for(int j = start; j < 5; ++j) {
                if (ds[j] < d) {
                    ans += pow(5, kWidth - i - 1);
                } else {
                    break;
                }
            }
            if(find(ds.begin(), ds.end(), d) == ds.end()) break;
        }
        // substract
        int cnt = 0;
        Dfs(str_num, "", &cnt);
        Dfs(str_num, "0", &cnt);
        Dfs(str_num, "1", &cnt);
        Dfs(str_num, "8", &cnt);
        return ans - cnt;
    }
    
private:
    const vector<pair<string, string>> pairs = {{"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}};
    void Dfs(const string & str_num, string cand, int * cnt) {
        if (cand.size() <= str_num.size()) {
            if (cand.size() > 0 && !(cand.size() > 1 && cand[0] == '0') && (cand.size() < str_num.size() || cand < str_num)) {
                ++(*cnt);
            }
            for(int i = 0; i < 5; ++i) {
                Dfs(str_num, pairs[i].first + cand + pairs[i].second, cnt);
            }
        } 
    }
};

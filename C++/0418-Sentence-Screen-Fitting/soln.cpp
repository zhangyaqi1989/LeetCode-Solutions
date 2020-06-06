class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int total = 0;
        vector<int> lens;
        for(string word : sentence) {
            int len = word.length();
            if (len > cols) return 0;
            total += len + 1;
            lens.push_back(len);
        }
        int ans = 0;
        int cur = 0, col = 0;
        int row = 0;
        while (rows > 0) {
            if (col == 0) {
                ans += cols / total;
                col = cols / total * total;
            }
            if(col + lens[cur] <= cols) {
                col += lens[cur] + 1;
                cur += 1;
                if (cur >= lens.size()) {
                    cur %= lens.size();
                    ++ans;
                }
            } else {
                col = 0;
                --rows;
                ++row;
                if (cur == 0) {
                    ans += ans * (rows / row);
                    rows %= row;
                }
            }
        }
        return ans;
    }
};

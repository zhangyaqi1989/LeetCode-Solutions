/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        // to the secret match
        int steps = 10;
        vector<string> ws(wordlist);
        while (steps-- > 0 && !ws.empty()) {
            int n = ws.size();
            // cout << n << endl;
            vector<vector<int>> matches(n, vector<int>(7, 0));
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    int cnt = count_matches(ws[i], ws[j]);
                    matches[i][cnt] += 1;
                    matches[j][cnt] += 1;
                }
            }
            int pick = 0, mn = n + 1;
            for(int i = 0; i < n; ++i) {
                int cur = *max_element(matches[i].begin(), matches[i].end());
                if (cur < mn) {
                    pick = i;
                    mn = cur;
                }
            }
            string g = ws[pick];
            int match = master.guess(g);
            // cout << g << endl;
            // cout << match << endl;
            if (match == 6) break;
            vector<string> nxt;
            for(int i = 0; i < n; ++i) {
                if (i == pick) continue;
                if (count_matches(ws[i], ws[pick]) == match) {
                    nxt.push_back(ws[i]);
                }
            }
            swap(nxt, ws);
        }
        
    }
    
    int count_matches(const string & w1, const string & w2) {
        int cnt = 0;
        for(int i = 0; i < 6; ++i) cnt += w1[i] == w2[i];
        return cnt;
    }
};

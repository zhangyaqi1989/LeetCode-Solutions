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
        for(int i = 0; i < 10; ++i) {
            int n = wordlist.size();
            int idx = rand() % n;
            string word = wordlist[idx];
            int match = master.guess(word);
            if (match == 6) break;
            vector<string> temp;
            for(string w : wordlist) {
                if (match == count_matches(w, word)) {
                    temp.push_back(w);
                }
            }
            swap(temp, wordlist);
        }
    }
    
    int count_matches(string & w1, string & w2) {
        int cnt = 0;
        for(int i = 0; i < 6; ++i) {
            if (w1[i] == w2[i]) ++cnt;
        }
        return cnt;
    }
};

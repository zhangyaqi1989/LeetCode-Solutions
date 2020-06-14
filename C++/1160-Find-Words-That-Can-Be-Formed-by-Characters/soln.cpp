class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counter_chars (26, 0);
        for(char ch : chars) ++counter_chars[ch - 'a'];
        int cnt = 0;
        for(const string & word : words) {
            vector<int> counter_word(26, 0);
            for(char ch : word) ++counter_word[ch - 'a'];
            bool valid = true;
            for(int i = 0; i < 26; ++i) {
                if(counter_word[i] > counter_chars[i]) {
                    valid = false;
                    break;
                }
            }
            if(valid) cnt += word.size();
        }
        return cnt;
    }
};

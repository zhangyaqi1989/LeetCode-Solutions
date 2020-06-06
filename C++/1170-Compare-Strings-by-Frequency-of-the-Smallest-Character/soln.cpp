class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> freqs;
        transform(words.begin(), words.end(), back_inserter(freqs), Frequency);
        sort(freqs.begin(), freqs.end());
        vector<int> ans;
        for(const string & query : queries) {
            int f = Frequency(query);
            ans.push_back(freqs.end() - upper_bound(freqs.begin(), freqs.end(), f));
        }
        return ans;
    }
    
private:
    static int Frequency(const string & word) {
        int chars[26] = {0};
        for(char ch : word) ++chars[ch - 'a'];
        for(int i = 0; i < 26; ++i) {
            if (chars[i]) return chars[i];
        }
        return 0;
    } 
};

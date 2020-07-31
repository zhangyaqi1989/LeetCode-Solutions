class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> positions(26, -1);
        for(size_t i = 0; i < keyboard.size(); ++i) {
            positions[keyboard[i] - 'a'] = i;
        }
        int ans = 0;
        for(size_t i = 0; i < word.length(); ++i) {
            if(i == 0) ans += positions[word[0] - 'a'];
            else ans += abs(positions[word[i] - 'a'] - positions[word[i - 1] - 'a']);
        }
        return ans;
    }
};

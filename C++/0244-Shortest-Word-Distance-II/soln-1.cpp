class WordDistance {
    map<string, vector<int>> idxes;
public:
    WordDistance(vector<string> words) {
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            idxes[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = INT_MAX;
        int n1 = idxes[word1].size(), n2 = idxes[word2].size();
        int i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            int v1 = idxes[word1][i1];
            int v2 = idxes[word2][i2];
            ans = min(ans, abs(v1 - v2));
            if (v1 < v2) {
                ++i1;
            } else {
                ++i2;
            }
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */

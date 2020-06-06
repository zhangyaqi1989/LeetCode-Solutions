class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banset(banned.begin(), banned.end());
        unordered_map<string, int> counter;
        for(auto & c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        string word, ans = "";
        int mx = 0;
        while (iss >> word) {
            if (banset.find(word) == banset.end() && ++counter[word] > mx) {
                mx = counter[word];
                ans = word;
            }
        }
        return ans;
    }
};

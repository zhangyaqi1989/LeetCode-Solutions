class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> idxes1;
        vector<int> idxes2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) idxes1.push_back(i);
            else if (words[i] == word2) idxes2.push_back(i);
        }
        int len = words.size();
        for(int i : idxes1)
            for(int j : idxes2)
                if (abs(i - j) < len)
                    len = abs(i - j);
        return len;
    }
};
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        const int n = words.size();
        for(int i = 0, k, l; i < n; i += k) {
            // k = 0; // number of words in current line
            // l = 0; // summation of length of words in current line
            for(k = 0, l = 0; i + k < n && l + words[i + k].size() + k <= maxWidth; ++k) {
                l += words[i + k].size();
            }
            string temp = "";
            if (i + k == n) {
                for(int j = 0; j < k; ++j) temp += words[i + j] + " ";
                temp.pop_back();
                temp += string(maxWidth - temp.size(), ' ');
            } else {
                // pad spaces
                int nspaces = maxWidth - l;
                if (k == 1) {
                    temp += words[i] + string(nspaces, ' ');
                } else {
                    int r = nspaces % (k - 1);
                    int q = nspaces / (k - 1);
                    for(int j = 0; j < k - 1; ++j) {
                        temp += words[i + j] + string(q, ' ');
                        if (j < r) temp += ' ';
                    }
                    temp += words[i + k - 1];
                }   
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < words[i].size(); ++j)
            {
                if(j >= m || i >= words[j].size() || words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
    }
};
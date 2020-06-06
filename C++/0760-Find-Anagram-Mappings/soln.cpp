class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, vector<int>> m;
        for(int i = 0; i < B.size(); ++i) {
            m[B[i]].push_back(i);
        }
        vector<int> ans;
        for(auto num : A) {
            ans.push_back(m[num].back());
            m[num].pop_back();
        }
        return ans;
    }
};

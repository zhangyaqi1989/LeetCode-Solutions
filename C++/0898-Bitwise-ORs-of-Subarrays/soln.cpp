class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur, res, temp;
        for(int x : A) {
            temp.clear();
            for(int y : cur) temp.insert(x | y);
            temp.insert(x);
            for(int y : temp) res.insert(y);
            swap(temp, cur);
        }
        return res.size();
    }
};

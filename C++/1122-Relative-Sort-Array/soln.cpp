class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> idxes(1001, 2000);
        int n2 = arr2.size();
        for(int i = 0; i < n2; ++i) idxes[arr2[i]] = i;
        vector<pair<int, int>> temp;
        for(int num : arr1) temp.emplace_back(idxes[num], num);
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(auto & p : temp) ans.push_back(p.second);
        return ans;
    }
};

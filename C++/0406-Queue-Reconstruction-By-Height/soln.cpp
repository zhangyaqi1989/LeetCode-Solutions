auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ALG: sort
// 
bool mySort(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}


class Solution {
public:
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans;
        sort(people.begin(), people.end(), mySort);
        for(auto p : people) {
            ans.insert(ans.begin() + p.second, p);
        }
        return ans;
    }
};

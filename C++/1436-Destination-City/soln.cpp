class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> cities;
        for(auto & p : paths) cities.insert(p[0]);
        for(auto & p : paths) {
            if(!cities.count(p[1])) return p[1];
        }
        return "";
    }
};

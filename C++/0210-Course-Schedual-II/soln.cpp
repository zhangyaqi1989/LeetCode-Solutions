class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> pres;
        unordered_map<int, unordered_set<int>> sucs;
        for (auto pair : prerequisites) {
            int suc = pair.first;
            int pre = pair.second;
            pres[suc].insert(pre);
            sucs[pre].insert(suc);
        }
        unordered_set<int> frees;
        for(int i = 0; i < numCourses; ++i) {
            if(pres.find(i) == pres.end()) frees.insert(i);
        }
        vector<int> ans;
        while (!frees.empty()) {
            auto course = *frees.begin();
            ans.push_back(course);
            frees.erase(frees.begin());
            auto fd = sucs.find(course);
            if (fd != sucs.end()) {
                for(auto nei : sucs[course]) {
                    if(pres[nei].size() == 1) {
                        pres.erase(nei);
                        frees.insert(nei);
                    } else if (pres[nei].size() > 1) {
                        pres[nei].erase(course);
                    }
                }
                
                sucs.erase(fd); 
            }
        }
        if (ans.size() != numCourses) ans.clear();
        return ans;
    }
};
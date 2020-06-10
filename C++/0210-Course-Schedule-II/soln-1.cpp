class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses, 0);
        vector<vector<int>> follows(numCourses);
        for(auto & temp : prerequisites) {
            int course = temp[0], req = temp[1];
            ++degrees[course];
            follows[req].push_back(course);
        }
        vector<int> frees;
        for(int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) frees.push_back(i);
        }
        vector<int> ans;
        while (!frees.empty()) {
            int node = frees.back();
            frees.pop_back();
            ans.push_back(node);
            for(int nei : follows[node]) {
                if (--degrees[nei] == 0) {
                    frees.push_back(nei);
                }
            }
        }
        if (ans.size() != numCourses) ans.clear();
        return ans;
    }
};

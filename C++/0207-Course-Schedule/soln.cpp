class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int degrees[numCourses] = {0};
        vector<int> graph[numCourses];
        stack<int> frees;
        for(auto & ab : prerequisites) {
            int a = ab.first, b = ab.second;
            graph[b].push_back(a);
            ++degrees[a];
        }
        for(int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) frees.push(i);
        }
        int cnt = 0;
        while(!frees.empty()) {
            int node = frees.top();
            frees.pop();
            ++cnt;
            for(int nei : graph[node]) {
                if (--degrees[nei] == 0) frees.push(nei);
            }
        }
        return cnt == numCourses;
    }
};

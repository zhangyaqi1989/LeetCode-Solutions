class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        // construct 
        unordered_map<string, set<string>> graph;
        for(auto & it : pairs) {
            graph[it.first].insert(it.second);
            graph[it.second].insert(it.first);
        }
        int n1 = words1.size(), n2 = words2.size();
        if (n1 != n2) return false;
        for(int i = 0; i < n1; ++i) {
            string word1 = words1[i], word2 = words2[i];
            if (word1 == word2) continue;
            if (!dfs(graph, word1, word2)) return false;
        }
        return true;
        
    }
    
    bool dfs(unordered_map<string, set<string>> & graph, string & start, string & target) {
        stack<string> s;
        set<string> visited;
        s.push(start);
        visited.insert(start);
        while (!s.empty()) {
            string cur = s.top();
            s.pop();
            if (cur == target) return true;
            for(auto nei : graph[cur]) {
                if(visited.find(nei) == visited.end()) {
                    visited.insert(nei);
                    s.push(nei);
                }
            }
        }
        return false;
    }
};

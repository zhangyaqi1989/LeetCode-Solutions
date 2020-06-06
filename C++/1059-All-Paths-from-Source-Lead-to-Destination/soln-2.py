class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(const vector<int> & edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        if (!graph[destination].empty()) return false;
        vector<int> marks(n, 0);
        return Dfs(source, destination, graph, &marks);
    }
    
private:
   bool Dfs(int node, int destination, const vector<vector<int>> & graph, vector<int> * marks) {
       if (graph[node].empty() && node != destination) return false;
       (*marks)[node] = true;
       for(int nei : graph[node]) {
           if(!(*marks)[nei]) {
               if (!Dfs(nei, destination, graph, marks)) return false;
           } else {
               return false;
           }
       }
       (*marks)[node] = false;
       return true;
   } 
    
    
};

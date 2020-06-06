/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // nodes are labeled uniquely
        if (node == nullptr) return nullptr;
        // do a traverse on the graph, build v and e
        map<int, UndirectedGraphNode *> m;
        m[node->label] = new UndirectedGraphNode(node->label);
        stack<UndirectedGraphNode *> s;
        s.push(node);
        while (!s.empty()) {
            UndirectedGraphNode * cur = s.top();
            s.pop();
            for(auto nei : cur->neighbors) {
                if(m.find(nei->label) == m.end()) {
                    m[nei->label] = new UndirectedGraphNode(nei->label);
                    s.push(nei);
                }
                m[cur->label]->neighbors.push_back(m[nei->label]);
            }
        }
        return m[node->label];
    }
};

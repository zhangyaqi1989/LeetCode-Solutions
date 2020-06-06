class Solution {
public:
    void dfs(vector<string> & path, string target, vector<vector<string>> & ans, unordered_map<string, unordered_set<string>> & prevs) {
        if (path.back() == target) {
            ans.push_back(path);
        } else {
            for (string prev : prevs[path.back()]) {
                path.push_back(prev);
                dfs(path, target, ans, prevs);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (words.find(endWord) == words.end()) return ans;
        queue<string> frontier;
        frontier.push(beginWord);
        unordered_map<string, int> costs;
        for(string word : words) costs[word] = INT_MAX;
        costs[beginWord] = 0;
        unordered_map<string, unordered_set<string>> prevs;
        int mn_cost = INT_MAX;
        while (!frontier.empty()) {
            string node = frontier.front();
            frontier.pop();
            if (node == endWord) {
                mn_cost = min(mn_cost, costs[node]);
            }
            if (costs[node] > mn_cost) continue;
            for(int i = 0; i < node.length(); ++i) {
                string nei(node);
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    nei[i] = ch;
                    if (words.count(nei) && costs[nei] >= costs[node] + 1) {
                        if (costs[nei] == costs[node] + 1) {
                            prevs[nei].insert(node);
                        } else {
                            prevs[nei].clear();
                            prevs[nei].insert(node);
                        }
                        costs[nei] = costs[node] + 1;
                        frontier.push(nei);
                    }
                }
            }
        }
        vector<string> path = {endWord};
        dfs(path, beginWord, ans, prevs);
        for (auto & item : ans) reverse(item.begin(), item.end()); 
        return ans;
    }
};

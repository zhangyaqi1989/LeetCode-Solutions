class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> bs;
        for(vector<int> p : blocked) {
            bs.insert({p[0], p[1]});
        }
        // return false;
        return bfs(bs, source, target) + bfs(bs, target, source) > 1;
    }
    
    int bfs(set<pair<int, int>>& bs, vector<int> source, vector<int> target) {
        int dirs[] = {1, 0, -1, 0, 1};
        queue<vector<int>> q;
        q.push({source[0], source[1]});
        set<pair<int, int>> seen;
        seen.insert({source[0], source[1]});
        while (!q.empty()) {
            int size = q.size();
            if (size > bs.size()) return 1;
            for(int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                int r = node[0], c= node[1];
                if (r == target[0] && c == target[1]) return 2;
                for(int k = 0; k < 4; ++k) {
                    int newr = r + dirs[k], newc = c + dirs[k + 1];
                    if (0 <= newr && newr < 1000000 && 0 <= newc && newc < 1000000) {
                        if (seen.find({newr, newc}) == seen.end() && bs.find({newr, newc}) == bs.end()) {
                            seen.insert({newr, newc});
                            q.push({newr, newc});
                        }                        
                    }

                }
            }
        }
        return 0;
    }
};

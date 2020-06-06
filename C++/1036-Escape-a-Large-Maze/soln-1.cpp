class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> blocks;
        for(const auto & b : blocked) blocks.insert({b[0], b[1]});
        return isBlocked(source, target, blocks) + isBlocked(target, source, blocks) > 1;
    }
    
private:
    int isBlocked(const vector<int> & source, const vector<int> & target, const set<pair<int, int>> & blocks) {
        // BFS
        pair<int, int> src = {source[0], source[1]};
        pair<int, int> dest = {target[0], target[1]};
        map<pair<int, int>, int> levels;
        levels[src] = 0;
        vector<pair<int, int>> frontier = {src};
        int dirs[5] = {0, -1, 0, 1, 0};
        int steps = 0;
        while(!frontier.empty()) {
            vector<pair<int, int>> nxt_level;
            for(auto & p : frontier) {
                int i, j;
                tie(i, j) = p;
                if (i == dest.first && j == dest.second) return 2;
                for(int k = 0; k < 4; ++k) {
                    int di = dirs[k], dj = dirs[k + 1];
                    int ni = i + di, nj = j + dj;
                    if (0 <= ni && ni < 1000000 && 0 <= nj && nj < 1000000 && !blocks.count({ni, nj}) && 
                        levels.find({ni, nj}) == levels.end()) {
                        levels[{ni, nj}] = steps + 1;
                        nxt_level.push_back({ni, nj});
                    }
                }
            }
            ++steps;
            swap(frontier, nxt_level);
            if (frontier.size() > blocks.size()) return 1;
        }
        return 0;
    }
};

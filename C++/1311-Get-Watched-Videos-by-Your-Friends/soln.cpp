class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int kN = friends.size();
        vector<int> frontier = {id};
        vector<int> levels(kN, -1);
        levels[id] = 0;
        int nsteps = 0;
        while (!frontier.empty()) {
            if(level-- == 0) break;
            vector<int> next_level;
            for(int u : frontier) {
                for(int v : friends[u]) {
                    if (levels[v] == -1) {
                        levels[v] = nsteps + 1;
                        next_level.push_back(v);
                    }
                }
            }
            ++nsteps;
            swap(frontier, next_level);
        }
        unordered_map<string, int> counter;
        for(int u : frontier) {
            for(const string & video : watchedVideos[u]) {
                ++counter[video];
            }
        }
        vector<string> ans;
        for(const auto & p : counter) {
            ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end(), [&](const string & a, const string & b) {
            return counter[a] == counter[b] ? a < b : counter[a] < counter[b];
        });
        return ans;
    }
};

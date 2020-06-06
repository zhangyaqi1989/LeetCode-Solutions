class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS
        const string kWheel = "0123456789";
        const unordered_set<string> kDeadends(deadends.begin(), deadends.end());
        if (kDeadends.count("0000")) return -1;
        vector<string> frontier = {"0000"};
        unordered_map<string, int> levels;
        levels.insert({"0000", 0});
        int steps = 0;
        int ds[2] = {-1, 1};
        while (!frontier.empty()) {
            vector<string> next_level;
            for(string code : frontier) {
                if (code == target) return steps;
                for(int i = 0; i < 4; ++i) {
                    for(int j = 0; j < 2; ++j) {
                        int d = ds[j];
                        string next_code(code);
                        int idx = code[i] - '0';
                        idx = (idx + d) % 10;
                        if (idx < 0) idx += 10;
                        next_code[i] = kWheel[idx];
                        if (kDeadends.count(next_code)) continue;
                        auto it = levels.find(next_code);
                        if (it == levels.end() || it->second > steps + 1) {
                            levels.insert({next_code, steps + 1});
                            next_level.push_back(next_code);
                        }
                    }
                }
            }
            swap(frontier, next_level);
            ++steps;
        }
        return -1;
    }
};

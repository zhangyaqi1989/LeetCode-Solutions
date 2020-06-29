class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<char, pair<int, int>> dirs = {{'N', {0, -1}}, {'S', {0, 1}}, {'E', {1, 0}}, {'W', {-1, 0}}};
        unordered_set<int> visited = {0};
        int r = 0, c = 0;
        for(char ch : path) {
            auto [dr, dc] = dirs[ch];
            r += dr;
            c += dc;
            int key = r * (10000) + c;
            if(visited.count(key)) return true;
            visited.insert(key);
        }
        return false;
    }
};

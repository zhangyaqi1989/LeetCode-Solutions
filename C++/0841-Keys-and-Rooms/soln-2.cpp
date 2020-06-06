class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        vector<bool> opened(n, false);
        dfs(rooms, 0, opened);
        return count(opened.begin(), opened.end(), true) == n;
    }
    
private:
    void dfs(const vector<vector<int>>& rooms, int u, vector<bool> & opened) {
        opened[u] = true;
        for(int v : rooms[u]) {
            if (!opened[v]) dfs(rooms, v, opened);
        }
    }
};

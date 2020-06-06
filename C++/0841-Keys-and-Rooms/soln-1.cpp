class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        stack<int> s;
        s.push(0);
        int cnt = 0;
        while (!s.empty()) {
            int room = s.top();
            s.pop();
            ++cnt;
            for(int nei : rooms[room]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    s.push(nei);
                }
            }
        }
        return cnt == n;
    }
};

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (find(arr.begin(), arr.end(), 0) == arr.end()) return false;
        stack<int> frontier;
        frontier.push(start);
        const int kN = arr.size();
        vector<bool> seen(kN, false);
        seen[start] = true;
        while (!frontier.empty()) {
            int u = frontier.top();
            frontier.pop();
            if (arr[u] == 0) return true;
            if (u + arr[u] < kN and !seen[u + arr[u]]) {
                seen[u + arr[u]] = true;
                frontier.push(u + arr[u]);
            }
            if (u - arr[u] >= 0 and !seen[u - arr[u]]) {
                seen[u - arr[u]] = true;
                frontier.push(u - arr[u]);
            }
        }
        return false;
    }
};

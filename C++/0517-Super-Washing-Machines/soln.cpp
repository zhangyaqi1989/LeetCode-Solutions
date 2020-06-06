class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (sum % n != 0) return -1;
        int target = sum / n;
        int to_left = 0;
        int ans = 0;
        for(int cloth : machines) {
            int to_right = cloth - target - to_left;
            ans = max(ans, max(max(to_left, to_right), to_left + to_right));
            to_left = -to_right;
        }
        return ans;
    }
};

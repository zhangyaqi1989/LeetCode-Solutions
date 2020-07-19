class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> s;
        int best = 1e9;
        for(int num : arr) {
            unordered_set<int> ns = {num};
            for(int val : s) {
                ns.insert(val & num);
            }
            for(int val : ns) {
                best = min(best, abs(val - target));
            }
            swap(s, ns);
        }
        return best;
    }
};

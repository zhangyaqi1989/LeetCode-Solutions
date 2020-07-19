class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        set<int> s;
        int best = 1e9;
        for(int num : arr) {
            set<int> ns = {num};
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

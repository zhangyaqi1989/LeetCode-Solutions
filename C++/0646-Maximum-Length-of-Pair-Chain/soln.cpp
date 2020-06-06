bool compare(const vector<int> & a, const vector<int> & b) {
    if (a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int low = INT_MIN, cnt = 0;
        for(auto & p : pairs) {
            int start = p[0], end = p[1];
            // cout << start << " " << end << endl;
            if (start > low) {
                ++cnt;
                low = end;
            }
            cout << low << endl;
        }
        return cnt;
    }
};

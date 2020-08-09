class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        // C++ 
        sort(points.begin(), points.end(), 
             [](const vector<int> & lhs, const vector<int> & rhs) {
                return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0]; 
             });
        points.erase(unique(points.begin(), points.end()), points.end());
        int n = points.size();
        double center = (n % 2) ? (points[n / 2][0]) : 0.5 * (points[n / 2][0] + points[n / 2 - 1][0]);
        if(points.front()[0] == points.back()[0]) return true;
        int lo = 0, hi = n - 1;
        vector<pair<double, int>> lefts, rights;
        while(lo < hi) {
            if(center != points[lo][0]) lefts.emplace_back(center - points[lo][0], points[lo][1]);
            if(center != points[hi][0])rights.emplace_back(points[hi][0] - center, points[hi][1]);
            ++lo;
            --hi;
        }
        if(lefts.size() != rights.size()) return false;
        sort(lefts.begin(), lefts.end());
        sort(rights.begin(), rights.end());
        return equal(lefts.begin(), lefts.end(), rights.begin());
    }
};

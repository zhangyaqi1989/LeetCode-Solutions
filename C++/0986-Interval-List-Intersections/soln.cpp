/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> ans;
        int i = 0;
        for(int j = 0; j < B.size(); ++j) {
            int sb = B[j].start, eb = B[j].end;
            while(i < A.size()) {
                if (sb > A[i].end) i++;
                else if (eb < A[i].start) break;
                else {
                    ans.push_back(Interval(max(A[i].start, sb), min(A[i].end, eb)));
                    if (eb >= A[i].end) i++;
                    else break;
                }
            }
        }
        return ans;
    }
};

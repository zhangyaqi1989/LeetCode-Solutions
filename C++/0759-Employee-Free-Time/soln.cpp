/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
        vector<Interval*> times;
        for(const auto & lst : schedule) {
            times.insert(times.end(), lst.begin(), lst.end());
        }
        sort(times.begin(), times.end(), [](Interval * a, Interval * b)
             {return a->start == b->start ? a->end < b->end : a->start < b->start;});
        vector<Interval *> res;
        int low = -1;
        for(auto & it : times) {
            if (low != -1 && it->start > low) {
                // cout << low << " " << it->start << endl;
                res.push_back(new Interval(low, it->start));
                low = it->end;
            } else {
                low = max(low, it->end);
            }
        }
        return res;
    }
};

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
        auto comp = [] (const tuple<Interval *, int, int> & a, const tuple<Interval *, int, int> & b) 
        {Interval * inta = get<0>(a);
         Interval * intb = get<0>(b);
         return inta->start == intb->start ? inta->end > intb->end : inta->start > intb->start;};
        priority_queue<tuple<Interval *, int, int>, vector<tuple<Interval *, int, int>>, decltype(comp)> pq(comp);
        const int n = schedule.size();
        for(int i = 0; i < n; ++i) {
            if (!schedule[i].empty()) {
                pq.emplace(schedule[i][0], 1, i);
            }
        }
        vector<Interval*> ans;
        int low = -1;
        while (!pq.empty()) {
            Interval * ptr;
            int nxt, idx;
            tie(ptr, nxt, idx) = pq.top();
            pq.pop();
            if (low != -1 && ptr->start > low) {
                ans.push_back(new Interval(low, ptr->start));
                low = ptr->end;
            } else {
                low = max(low, ptr->end);
            }
            if (nxt < schedule[idx].size()) {
                pq.emplace(schedule[idx][nxt], nxt + 1, idx);
            }
        }
        return ans;
    }
};

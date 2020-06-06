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
        auto comp = [](const tuple<int, int, int> & a, const tuple<int, int, int> & b) {
          return get<0>(a) > get<0>(b);  
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> pq(comp);
        const int n = schedule.size();
        for(int i = 0; i < n; ++i) {
            if (schedule[i].empty()) continue;
            pq.push({schedule[i][0]->start, 1, i});
        }
        vector<Interval*> ans;
        int low = -1;
        while (!pq.empty()) {
            int s, nxt, idx;
            tie(s, nxt, idx) = pq.top();
            pq.pop();
            int e = schedule[idx][nxt - 1]->end;
            if (low == -1 || s <= low) low = max(low, e);
            else {
                ans.push_back(new Interval(low, s));
                low = max(low, e);
            }
            if (nxt < (int) schedule[idx].size()) pq.push({schedule[idx][nxt]->start, nxt + 1, idx});
        }
        return ans;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto mycmp = [&] (pair<int, int> & a, pair<int, int> & b) {
            if (a.first == b.first) return b.second < a.second;
            else return a.first < b.first;
        };
        sort(envelopes.begin(), envelopes.end(), mycmp);
        vector<int> heights;
        for(auto & p : envelopes) heights.push_back(p.second);
        vector<int> tails;
        for(int h : heights) {
            auto it = lower_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) tails.push_back(h);
            else *it = h;
        }
        return tails.size();
    }
};

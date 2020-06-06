bool MyComp(const pair<string, int> & a, const pair<string, int> & b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
} 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for(const string & word : words) ++counter[word];
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(& MyComp)> pq(MyComp);
        for(auto & p : counter) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        vector<string> tops;
        while (!pq.empty()) {
            tops.push_back(pq.top().first);
            pq.pop();
        }
        reverse(tops.begin(), tops.end());
        return tops;
    }
};

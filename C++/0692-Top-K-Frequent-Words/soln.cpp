class Compare {
    public:
    bool operator()(pair<string, int> & p1, pair<string, int> & p2) {
        if (p1.second != p2.second) return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto & word : words) m[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for (auto & it : m) {
            pq.emplace(it.first, it.second);
            if (pq.size() > k) pq.pop();
        }
        vector<string> ret;
        for(int i = 0; i < k; ++i) {
            auto temp = pq.top();
            ret.push_back(temp.first);
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

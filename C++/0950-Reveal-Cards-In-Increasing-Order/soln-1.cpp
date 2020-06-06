class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        const int n = deck.size();
        deque<int> dq;
        for(int i = 0; i < n; ++i) dq.push_back(i);
        vector<int> ans(n, -1);
        sort(deck.begin(), deck.end());
        auto it = deck.begin();
        while (!dq.empty()) {
            int idx = dq.front();
            dq.pop_front();
            ans[idx] = (*it);
            it = next(it);
            if (!dq.empty()) {
                int nxt = dq.front();
                dq.pop_front();
                dq.push_back(nxt);
            }
        }
        return ans;
    }
};

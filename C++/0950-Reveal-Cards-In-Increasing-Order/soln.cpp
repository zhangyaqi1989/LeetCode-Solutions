class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        sort(deck.begin(), deck.end(), greater<int>());
        for(auto v : deck) {
            if (dq.size()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(v);
        }
        vector<int> ans(dq.begin(), dq.end());
        return ans;
    }
};
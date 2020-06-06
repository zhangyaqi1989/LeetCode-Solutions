class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // for each offer, can I use more than once?
        // early prune
        prices_ = price;
        specials_ = special;
        int best = 0;
        const int kN = needs.size();
        for(int i = 0; i < kN; ++i) best += price[i] * needs[i];
        Dfs(0, 0, & needs, & best);
        return best;
    }
    
private:
    vector<int> prices_;
    vector<vector<int>> specials_;
    void Dfs(int idx, int cur, vector<int> * need, int * best) {
        if (cur >= *best) return;
        bool valid = true;
        for(auto it = need->begin(); it != need->end(); ++it) {
            if(*it > 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            *best = min(*best, cur);
        } else {
            const int kM = specials_.size();
            const int kN = need->size();
            int temp = cur;
            for(int j = 0; j < kN; ++j) {
                temp += need->at(j) * prices_[j];
            }
            *best = min(*best, temp);
            for(int i = idx; i < kM; ++i) {
                bool valid_offer = true;
                for(int j = 0; j < kN; ++j) {
                    if (need->at(j) < specials_[i][j]) {
                        valid_offer = false;
                        break;
                    }
                }
                if (valid_offer) {
                    for(int j = 0; j < kN; ++j) {
                        need->at(j) -= specials_[i][j];
                    }
                    Dfs(i, cur + specials_[i].back(), need, best);
                    for(int j = 0; j < kN; ++j) {
                        need->at(j) += specials_[i][j];
                    }
                }
            }
        }
        
    }
};

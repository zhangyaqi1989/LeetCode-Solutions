class Leaderboard {
public:
    Leaderboard() {
        board_.clear();
        scores_.clear();
    }
    
    void addScore(int playerId, int score) {
        auto it = scores_.find(playerId);
        if (it == scores_.end()) {
            scores_.insert({playerId, score});
            board_.insert({-score, playerId});
        } else {
            board_.erase({-it->second, playerId});
            it->second += score;
            board_.insert({-it->second, playerId});
        }
        
    }
    
    int top (int K) {
        auto it = board_.begin();
        int ans = 0;
        while (K-- > 0 && it != board_.end()) {
            ans += -(it->first);
            ++it;
        }
        return ans;
    }
    
    void reset(int playerId) {
        int old_score = scores_[playerId];
        board_.erase({-old_score, playerId});
        board_.insert({0, playerId});
        scores_[playerId] = 0;
    }
    
private:
    set<pair<int, int>> board_;
    unordered_map<int, int> scores_;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

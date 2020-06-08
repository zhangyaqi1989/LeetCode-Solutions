class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history_.push_back(homepage);
        idx_ = 0;
    }
    
    void visit(string url) {
        history_.erase(history_.begin() + idx_ + 1, history_.end());
        history_.push_back(url);
        ++idx_;
    }
    
    string back(int steps) {
        idx_ = max(0, idx_ - steps);
        return history_[idx_];
    }
    
    string forward(int steps) {
        idx_ = min(static_cast<int>(history_.size()) - 1, idx_ + steps);
        return history_[idx_];
    }
    
private:
    vector<string> history_;
    int idx_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

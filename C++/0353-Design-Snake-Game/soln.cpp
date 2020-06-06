class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        body_.push_back({0, 0});
        dirs_["U"] = {-1, 0};
        dirs_["D"] = {1, 0};
        dirs_["L"] = {0, -1};
        dirs_["R"] = {0, 1};
        width_ = width;
        height_ = height;
        score_ = 0;
        food_ = food;
        reverse(food_.begin(), food_.end());
        occupied_.assign(height, vector<bool>(width, false));
        occupied_[0][0] = true;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> drc = dirs_[direction];
        int head_r = body_.back().first + drc.first, head_c = body_.back().second + drc.second;
        if (head_r < 0 || head_r >= height_ || head_c < 0 || head_c >= width_) return -1;
        int score = 0;
        if (!food_.empty() && food_.back()[0] == head_r && food_.back()[1] == head_c) {
            food_.pop_back();
            ++score_;
            if (occupied_[head_r][head_c]) return -1;
            body_.push_back({head_r, head_c});
            occupied_[head_r][head_c] = true;
        } else {
            occupied_[body_.front().first][body_.front().second] = false;
            body_.pop_front();
            if (occupied_[head_r][head_c]) return -1;
            body_.push_back({head_r, head_c});
            occupied_[head_r][head_c] = true;
        }
        return score_;
    }
    
private:
    deque<pair<int, int>> body_;
    unordered_map<string, pair<int, int>> dirs_;
    int width_;
    int height_;
    int score_;
    vector<vector<int>> food_;
    vector<vector<bool>> occupied_;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

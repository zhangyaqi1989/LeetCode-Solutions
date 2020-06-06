class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!stk.empty() && stk.back().first <= price) {
            span += stk.back().second;
            stk.pop_back();
        }
        stk.emplace_back(price, span);
        return span;
    }
    
private:
    vector<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

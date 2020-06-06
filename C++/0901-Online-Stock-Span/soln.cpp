// less than or equal to
// remember
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (prices.empty()) {
            prices.push_back(price);
            spans.push_back(1);
            return 1;
        } else {
            int pre = prices.back();
            // prices.push_back(price);
            int n = prices.size();
            int span = 1;
            for(int i = n - 1; i >= 0;) {
                if (prices[i] <= price) {
                    span += spans[i];
                    i -= spans[i];
                } else {
                    break;
                }
            }
            prices.push_back(price);
            spans.push_back(span);
            return span;
        }
    }
    
private:
    vector<int> prices;
    vector<int> spans;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

const int kProducts = 205;

class Cashier {
    int n_;
    int discount_;
    int prices_ [kProducts];
    int cnt_;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices): n_(n), discount_(discount){
        memset(prices_, 0, sizeof(prices_));
        const int kN = products.size();
        for(int i = 0; i < kN; ++i) {
            prices_[products[i]] = prices[i];
        }
        cnt_ = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double price = 0.0;
        const int kN = product.size();
        for(int i = 0; i < kN; ++i) {
            price += prices_[product[i]] * amount[i];
        }
        if (++cnt_ == n_) {
            price = (100 - discount_) / 100.0 * price;
            cnt_ = 0;
        }
        return price;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

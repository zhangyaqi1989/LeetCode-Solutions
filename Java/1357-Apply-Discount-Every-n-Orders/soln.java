class Cashier {
    private int n_;
    private int discount_;
    private int cnt_;
    private int [] prices_;

    public Cashier(int n, int discount, int[] products, int[] prices) {
        n_ = n;
        discount_ = discount;
        cnt_ = 0;
        int m = products.length;
        prices_ = new int [205];
        for(int i = 0; i < m; ++i) {
            prices_[products[i]] = prices[i];
        }
    }
    
    public double getBill(int[] product, int[] amount) {
        double price = 0.0;
        int m = product.length;
        for(int i = 0; i < m; ++i) {
            price += prices_[product[i]] * amount[i];
        }
        if (++cnt_ == n_) {
            price = (100 - discount_) / 100.0 * price;
            cnt_ = 0;
        }
        return price;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */

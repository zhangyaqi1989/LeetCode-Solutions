class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> codes;
        for(const auto & w : words) {
            int code = 0;
            for(char ch : w) {
                code |= (1 << (ch - 'a'));
            }
            int len = w.length();
            auto it = codes.find(code);
            if (it == codes.end()) codes.insert({code, len});
            else it->second = max(it->second, len);
        }
        int max_product = 0;
        for(auto it1 = codes.begin(); it1 != codes.end(); ++it1) {
            for(auto it2 = next(it1); it2 != codes.end(); ++it2) {
                if (!(it1->first & it2->first)) 
                    max_product = max(max_product, it1->second * it2->second);
            }
        }
        return max_product;
    }
};

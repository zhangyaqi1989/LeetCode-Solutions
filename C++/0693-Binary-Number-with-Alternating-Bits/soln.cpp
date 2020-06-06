class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> v;
        while(n != 0) {
            v.push_back(n % 2);
            n /= 2;
        }
        int len = v.size();
        for(int i = 0; i < len - 1; ++i) {
            if(v[i] == v[i + 1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        // each group has exactly X cards
        // all the group have the same integer
        const int kN = 10001;
        int counter[kN] = {0};
        for(int num : deck) ++counter[num];
        int a = -1;
        for(int i = 0; i < kN; ++i) {
            if(counter[i]) {
                if(a == -1) a = counter[i];
                else {
                    a = __gcd(a, counter[i]);
                }
            }
        }
        return a >= 2;
    }
};

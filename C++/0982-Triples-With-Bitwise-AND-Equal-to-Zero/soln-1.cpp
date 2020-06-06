class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> cnts(1<<16, -1);
        int ans = 0;
        for(auto a : A)
            for(auto b : A) {
                int c = a & b;
                if (cnts[c] != -1) {
                    ans += cnts[c];
                } else {
                    cnts[c] = 0;
                    for(auto d : A) {
                        if ((d & c) == 0)
                            ++cnts[c];
                    }
                    ans += cnts[c];
                }
            }
        return ans;
    }
};

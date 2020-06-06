class Solution {
public:
    int findLucky(vector<int>& arr) {
        const int kN = 501;
        vector<int> counter(kN, 0);
        for(int num : arr) ++counter[num];
        for(int i = kN - 1; i > 0; --i) {
            if(counter[i] == i) return i;
        }
        return -1;
    }
};

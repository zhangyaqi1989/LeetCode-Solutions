class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        int i = 0;
        for(int j = 0; j < flowerbed.size(); ++j) {
            if(flowerbed[j] == 1) {
                if (j != i) {
                    n -= (j - i - 1) / 2;
                    if (n <= 0) return true;
                }
                i = j + 1;
            }
        }
        return false;
        
    }
};
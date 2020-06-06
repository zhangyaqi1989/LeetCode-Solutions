class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        vector<int> array = {1};
        while (array.size() < n)
        {
            while (array[i2] * 2 <= array[array.size() - 1]) ++i2;
            while (array[i3] * 3 <= array[array.size() - 1]) ++i3;
            while (array[i5] * 5 <= array[array.size() - 1]) ++i5;
            array.push_back(min(array[i2] * 2, min(array[i3] * 3, array[i5] * 5)));
        }
        return array[n - 1];
    }
};
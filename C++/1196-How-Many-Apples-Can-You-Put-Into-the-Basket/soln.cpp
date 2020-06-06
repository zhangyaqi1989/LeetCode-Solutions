class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int basket = 0, cnt = 0;
        sort(arr.begin(), arr.end());
        for(int num : arr) {
            if (basket + num <= 5000) {
                basket += num;
                ++cnt;
            }
        }
        return cnt;
    }
};

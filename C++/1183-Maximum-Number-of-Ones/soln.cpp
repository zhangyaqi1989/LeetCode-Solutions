class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> arr;
        for(int i = 0; i < sideLength; ++i) {
            for(int j = 0; j < sideLength; ++j) {
                arr.push_back(((height - i - 1) / sideLength + 1) * ((width - j - 1) / sideLength + 1));
            }
        }
        sort(arr.rbegin(), arr.rend());
        int ans = 0;
        for(int num : arr) {
            if (maxOnes-- == 0) return ans;
            ans += num;
        }
        return ans;
        
    }
};

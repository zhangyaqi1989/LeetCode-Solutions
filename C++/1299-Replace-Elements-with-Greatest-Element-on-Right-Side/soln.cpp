class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int right = -1;
        const int kN = arr.size();
        for(int i = kN - 1; i >= 0; --i) {
            int num = arr[i];
            arr[i] = right;
            right = max(right, num);
        }
        return arr;
    }
};

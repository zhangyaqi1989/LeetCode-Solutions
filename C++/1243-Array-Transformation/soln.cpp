class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        const int n = arr.size();
        bool change = true;
        vector<int> nxt(n);
        while (change) {
            change = false;
            nxt[0] = arr[0];
            nxt[n - 1] = arr[n - 1];
            for(int i = 1; i < n - 1; ++i) {
                if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    change = true;
                    nxt[i] = arr[i] + 1;
                } else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    change = true;
                    nxt[i] = arr[i] - 1;
                } else nxt[i] = arr[i];
            }
            swap(arr, nxt);
        }
        return arr;
    }
};

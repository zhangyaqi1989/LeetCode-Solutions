class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        const int kN = arr.size();
        while (true) {
            bool change = false;
            vector<int> new_arr(arr);
            for(int i = 1; i < kN - 1; ++i) {
                if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    ++new_arr[i];
                    change = true;
                }
                if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    --new_arr[i];
                    change = true;
                }
            }
            swap(arr, new_arr);
            if(!change) break;
        }
        return arr;
    }
};

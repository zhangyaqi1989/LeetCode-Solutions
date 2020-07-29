class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        for(int num : arr1) {
            if(IsIn(arr2, num) && IsIn(arr3, num)) ans.push_back(num);
        }
        return ans;
    }
    
private:
    bool IsIn(const vector<int> & arr, int num) {
        auto it = lower_bound(arr.begin(), arr.end(), num);
        return it != arr.end() && (*it) == num;
    }
};

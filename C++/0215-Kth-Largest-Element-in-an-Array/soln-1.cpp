class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return select(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
private:
    int select(vector<int> & nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int pivot = left + rand() % (right - left + 1);
        pivot = partition(nums, left, right, pivot);
        if (k == pivot) return nums[k];
        else if (k < pivot) {
            return select(nums, left, pivot - 1, k);
        } else {
            return select(nums, pivot + 1, right, k);
        }
    }
    
    int partition(vector<int> & nums, int left, int right, int pivot) {
        int pv = nums[pivot];
        swap(nums[pivot], nums[right]);
        int idx = left;
        for(int i = left; i < right; ++i) {
            if (nums[i] < pv){
                swap(nums[idx], nums[i]);
                ++idx;
            }
        }
        swap(nums[idx], nums[right]);
        return idx;
    }
};

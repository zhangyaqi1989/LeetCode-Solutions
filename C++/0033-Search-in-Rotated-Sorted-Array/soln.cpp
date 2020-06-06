class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < nums[r])
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
                
            } else
            {
                if (target < nums[mid] && target >= nums[l])
                    r = mid - 1;
                else
                    l = mid + 1;  
            }
        }
        return -1;
    }
};
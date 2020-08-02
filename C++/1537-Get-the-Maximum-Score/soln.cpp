class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long cur1 = 0, cur2 = 0, ans = 0;
        const int kN1 = nums1.size();
        const int kN2 = nums2.size();
        int i = 0, j = 0;
        while(i < kN1 && j < kN2) {
            if(nums1[i] < nums2[j]) {
                cur1 += nums1[i++];
            } else if(nums1[i] > nums2[j]) {
                cur2 += nums2[j++];
            } else {
                ans += max(cur1, cur2) + nums1[i];
                cur1 = 0;
                cur2 = 0;
                ++i;
                ++j;
            }
        }
        cur1 += accumulate(nums1.begin() + i, nums1.end(), 0LL);
        cur2 += accumulate(nums2.begin() + j, nums2.end(), 0LL);
        return (ans + max(cur1, cur2)) % 1000000007;
    }
};

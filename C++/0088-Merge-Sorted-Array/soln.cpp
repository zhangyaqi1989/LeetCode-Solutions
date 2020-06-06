class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n - 1;
        m = m - 1;
        n = n - 1;
        while (m >= 0 && n >= 0)
        {
            if (nums2[n] >= nums1[m]) nums1[j--] = nums2[n--];
            else nums1[j--] = nums1[m--];
        }
        if (n >= 0)
        {
            for(int i = n; i >= 0; i--)
                nums1[j--] = nums2[i];
        }
    }
};
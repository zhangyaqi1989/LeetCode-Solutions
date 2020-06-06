class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        if (n % 2 == 1) {
            return kth(nums1, 0, n1, nums2, 0, n2, n / 2);
        } else {
            return 0.5 * (kth(nums1, 0, n1, nums2, 0, n2, n / 2) + kth(nums1, 0, n1, nums2, 0, n2, n / 2 - 1));
        }
    }
    
private:
    // [l, r)
    int kth(vector<int> & nums1, int l1, int r1, vector<int> & nums2, int l2, int r2, int k) {
        if (r1 <= l1) return nums2[l2 + k];
        if (r2 <= l2) return nums1[l1 + k];
        int h1 = (r1 - l1) / 2;
        int h2 = (r2 - l2) / 2;
        int m1 = l1 + h1;
        int m2 = l2 + h2;
        int half = h1 + h2;
        if (k <= half) {
            if (nums1[m1] > nums2[m2]) return kth(nums1, l1, m1, nums2, l2, r2, k);
            else return kth(nums1, l1, r1, nums2, l2, m2, k);
        } else {
            if (nums1[m1] < nums2[m2]) return kth(nums1, m1 + 1, r1, nums2, l2, r2, k - h1 - 1);
            else return kth(nums1, l1, r1, nums2, m2 + 1, r2, k - h2 - 1);
        }
    }
};

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0;
        int r = numbers.length - 1;
        while (l < r)
        {
            int s = numbers[l] + numbers[r];
            if (s == target) break;
            else if (s < target) l++;
            else r--;
        }
        return new int[]{l + 1, r + 1};
    }
}
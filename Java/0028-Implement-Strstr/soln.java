class Solution {
    public int strStr(String haystack, String needle) {
        int ans = haystack.indexOf(needle);
        return ans == -1 ? -1 : ans;
    }
}

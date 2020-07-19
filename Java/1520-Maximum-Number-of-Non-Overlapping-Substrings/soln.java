class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int [] left = new int [26];
        Arrays.fill(left, -1);
        int [] right = new int [26];
        for(int i = 0; i < s.length(); ++i) {
            int idx = s.charAt(i) - 'a';
            if(left[idx] == -1) left[idx] = i;
            right[idx] = i;
        }
        ArrayList<int []> intervals = new ArrayList<>();
        for(int i = 0; i < 26; ++i) {
            if(left[i] != -1) {
                int lo = left[i];
                int hi = right[i];
                for(int j = left[i]; j <= right[i]; ++j) {
                    int idx = s.charAt(j) - 'a';
                    lo = Math.min(lo, left[idx]);
                    hi = Math.max(hi, right[idx]);
                }
                int l = left[i], r = right[i];
                while(l > lo || r < hi) {
                    if(l > lo) {
                        int idx = s.charAt(l--) - 'a';
                        lo = Math.min(lo, left[idx]);
                        hi = Math.max(hi, right[idx]);
                    }
                    if(r < hi) {
                        int idx = s.charAt(r++) - 'a';
                        lo = Math.min(lo, left[idx]);
                        hi = Math.max(hi, right[idx]);
                    }
                }
                intervals.add(new int [] {lo, hi});
            }
        }
        Collections.sort(intervals, (a, b) -> (
            a[1] == b[1] ? (a[1] - a[0]) - (b[1] - b[0]) : a[1] - b[1]
        ));
        int lo = -1;
        List<String> ans = new ArrayList<>();
        for(int [] interval : intervals) {
            int a = interval[0], b = interval[1];
            if(a > lo) {
                ans.add(s.substring(a, b + 1));
                lo = b;
            }
        }
        return ans;
    }
}

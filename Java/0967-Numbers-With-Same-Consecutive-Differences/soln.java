class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        int start = (N == 1 ? 0 : 1);
        List<Integer> sub = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        for(int i = start; i < 10; ++i) {
            sub.add(i);
            helper(N, K, sub, ans);
            sub.remove(sub.size() - 1);
        }
        int[] nums = new int[ans.size()];
        for(int i = 0; i < ans.size(); ++i) nums[i] = ans.get(i);
        return nums;
    }
    
    public void helper(int N, int K, List<Integer> sub, List<Integer> ans) {
        if (sub.size() == N) {
            int num = 0;
            for(int d : sub) num = num * 10 + d;
            ans.add(num);
        } else {
            int num = sub.get(sub.size() - 1);
            if (0 <= num + K && num + K < 10) {
                sub.add(num + K);
                helper(N, K, sub, ans);
                sub.remove(sub.size() - 1);
            }
            if (K != 0) {
                if (0 <= num - K && num - K < 10) {
                    sub.add(num - K);
                    helper(N, K, sub, ans);
                    sub.remove(sub.size() - 1);
                }
            }
        }
    }
}

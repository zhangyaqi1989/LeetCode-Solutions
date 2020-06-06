class Solution {
    public int numRabbits(int[] answers) {
        if (answers.length == 0) return 0;
        Arrays.sort(answers);
        int ans = 0, cnt = 0, cur = answers[0];
        for(int num : answers) {
            if (num > cur) {
                // System.out.println(cnt);
                ans += (cur + 1) * ((cnt + cur) / (cur + 1));
                cur = num;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        ans += (cur + 1) * ((cnt + cur) / (cur + 1));
        return ans;
    }
}

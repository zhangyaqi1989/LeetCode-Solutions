class Solution {
    public String nextClosestTime(String time) {
        int idx = time.indexOf(':');
        int H = Integer.parseInt(time.substring(0, idx));
        int M = Integer.parseInt(time.substring(idx + 1));
        Set<Character> chars = new HashSet<>();
        for(char ch : time.toCharArray()) chars.add(ch);
        int mins = H * 60 + M;
        int diff = 1441;
        String ans = "00:00";
        for(int num = 0; num < 1440; ++num) {
            int h = num / 60, m = num % 60;
            String t = String.format("%02d:%02d", h, m);
            boolean valid = true;
            for(char ch : t.toCharArray()) {
                if (!chars.contains(ch)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                int cur_diff = num <= mins ? num - mins + 1440 : num - mins;
                if (cur_diff < diff) {
                    diff = cur_diff;
                    ans = t;
                }
            }
        }
        return ans;
    }
}

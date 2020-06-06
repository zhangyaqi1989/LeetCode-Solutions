class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        List<Integer> leftRs = new ArrayList<>();
        int left_R = -1;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            char d = dominoes.charAt(i);
            if (d == 'R') {
                left_R = 0;
                sb.append('R');
            } else if (d == 'L') {
                left_R = -1;
                sb.append('L');
            } else {
                if (left_R != -1) {
                    ++left_R;
                    sb.append('R');
                } else {
                    sb.append('.');
                }
            }
            leftRs.add(left_R);
        }
        int right_L = -1;
        for(int i = n - 1; i >= 0; --i) {
            char d = dominoes.charAt(i);
            if (d == 'L') {
                right_L = 0;
            } else if (d == 'R') {
                right_L = -1;
            } else {
                if (right_L != -1) {
                    ++right_L;
                    if (leftRs.get(i) == -1 || right_L < leftRs.get(i)) {
                        sb.setCharAt(i, 'L');
                    }
                    if (right_L == leftRs.get(i)) {
                        sb.setCharAt(i, '.');
                    }
                }
            }
        }
        return sb.toString();
    }
}

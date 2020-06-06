class Solution {
    public int compress(char[] chars) {
        int cnt = 0, lo = 0, idx = 0;
        for(int i = 0; i < chars.length; ++i) {
            if(chars[i] != chars[lo]) {
                chars[idx++] = chars[lo];
                if(cnt > 1) {
                    String num_str = Integer.toString(cnt);
                    for(char ch : num_str.toCharArray()) {
                        chars[idx++] = ch;
                    }
                }
                lo = i;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        chars[idx++] = chars[lo];
        if (cnt > 1) {
            String num_str = Integer.toString(cnt);
            for(char ch : num_str.toCharArray()) {
                chars[idx++] = ch;
            }            
        }
        return idx;
    }
}

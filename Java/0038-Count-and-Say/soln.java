class Solution {
    public String countAndSay(int n) {
        String str = "1";
        for(int i = 1; i < n; ++i) {
            StringBuilder sb = new StringBuilder();
            int lo = 0;
            int len = str.length();
            for(int j = 0; j < len; ++j) {
                if(str.charAt(j) != str.charAt(lo)) {
                    int cnt = j - lo;
                    sb.append(Integer.toString(cnt));
                    sb.append(str.charAt(lo));
                    lo = j;
                }
            }
            sb.append(Integer.toString(len - lo));
            sb.append(str.charAt(lo));
            str = sb.toString();
        }
        return str;
    }
}

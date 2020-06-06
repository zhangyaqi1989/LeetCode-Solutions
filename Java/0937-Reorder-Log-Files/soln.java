class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String []> letters = new ArrayList<>();
        List<String> digits = new ArrayList<>();
        int n = logs.length;
        for(int i = 0; i < n; ++i) {
            String log = logs[i];
            int idx = log.indexOf(' ');
            String ident = log.substring(0, idx), rest = log.substring(idx + 1);
            if (Character.isDigit(rest.charAt(0))) {
                digits.add(log);
            } else {
                letters.add(new String[] {rest, ident, log});
            }
        }
        Collections.sort(letters, (a, b)->(a[0].equals(b[0]) ? a[1].compareTo(b[1]) : a[0].compareTo(b[0])));
        String[] ans = new String[n];
        int idx = 0;
        for(String [] p : letters) ans[idx++] = p[2];
        for(String log : digits) ans[idx++] = log;
        return ans;
    }
}

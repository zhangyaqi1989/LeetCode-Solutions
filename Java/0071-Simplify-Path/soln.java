class Solution {
    public String simplifyPath(String path) {
        List<String> stk = new ArrayList<>();
        int n = path.length();
        int idx = 0;
        while(idx < n) {
            while(idx < n && path.charAt(idx) == '/') ++idx;
            int lo = idx;
            while(idx < n && path.charAt(idx) != '/') ++idx;
            String name = path.substring(lo, idx);
            if (name.length() != 0) {
                if(name.equals(".")) continue;
                else if (name.equals("..")) {
                    if(!stk.isEmpty()) stk.remove(stk.size() - 1);
                } else {
                    stk.add(name);
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(String name : stk) {
            sb.append("/");
            sb.append(name);
        }
        String ans = sb.toString();
        return ans.isEmpty() ? "/" : ans;
    }
}

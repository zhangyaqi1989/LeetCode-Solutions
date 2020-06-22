class Solution {
    public String[] getFolderNames(String[] names) {
        int n = names.length;
        String[] ans = new String[n];
        HashMap<String, Integer> nxt = new HashMap<>();
        HashSet<String> seen = new HashSet<>();
        for(int i = 0; i < n; ++i) {
            String name = names[i];
            if(!seen.contains(name)) {
                ans[i] = name;
            } else {
                int suffix = nxt.getOrDefault(name, 1);
                while(seen.contains(name + "(" + Integer.toString(suffix) + ")")) {
                    ++suffix;
                }
                ans[i] = name + "(" + Integer.toString(suffix) + ")";
                nxt.put(name, suffix + 1);
            }
            seen.add(ans[i]);
        }
        return ans;
    }
}

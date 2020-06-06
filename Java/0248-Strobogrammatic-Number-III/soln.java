class Solution {
    public int strobogrammaticInRange(String low, String high) {
        int mn = low.length(), mx = high.length();
        Set<String> cands = new HashSet<>();
        for(int i = mn; i <= mx; ++i) {
            generate(i, cands, low, high);
        }
        return cands.size();
    }
    
    private void generate(int n, Set<String> cands, String low, String high) {
        List<String> ans = new ArrayList<>();
        if (n % 2 == 1) {
            ans.add("0");
            ans.add("1");
            ans.add("8");
        } else {
            ans.add("");
        }
        String [] pairs = {"00", "11", "88", "69", "96"};
        while (n > 1) {
            int start = n - 2 > 1 ? 0 : 1;
            List<String> temp = new ArrayList<>();
            for(String item : ans) {
                for(int j = start; j < 5; ++j) {
                    String p = pairs[j];
                    temp.add(p.charAt(0) + item + p.charAt(1));
                }
            }
            ans = temp;
            n -= 2;
        }
        for(String item : ans) {
            if (check(item, low, high)) cands.add(item);
        }
    }
    
    private boolean check(String item, String low, String high) {
        int n = item.length(), mn = low.length(), mx = high.length();
        if (n < mn || n > mx) return false;
        return (n > mn || item.compareTo(low) >= 0) && (n < mx || item.compareTo(high) <= 0);
    }
    
}

class Solution {
    private boolean valid(int x, int y) {
        int root = (int) Math.sqrt(x + y);
        return root * root == x + y;
    }
    public int numSquarefulPerms(int[] A) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : A) {
            Integer value = counter.get(num);
            if (value == null) value = 0;
            ++value;
            counter.put(num, value);
        }
        HashMap<Integer, ArrayList<Integer>> cands = new HashMap<>();
        for(int a : counter.keySet())
            for(int b : counter.keySet()) {
                if (valid(a, b)) {
                    if (cands.get(a) == null)
                        cands.put(a, new ArrayList<Integer>());
                    cands.get(a).add(b);
                }   
            }
        
        int [] ans = {0};
        for(int num : counter.keySet()) {
            helper(counter, cands, num, A.length - 1, ans);
        }
        return ans[0];
    }
    
    public void helper(Map<Integer, Integer> counter, HashMap<Integer, ArrayList<Integer>> cands, int cur, int left, int [] ans) {
        if (left == 0) {
            ans[0] += 1;
        }
        counter.put(cur, counter.get(cur) - 1);
        ArrayList<Integer> neighbors = cands.get(cur);
        if (neighbors != null){
            for(Integer nei : neighbors) {
                if (counter.get(nei) > 0)
                    helper(counter, cands, nei, left - 1, ans);
            }            
        }
        counter.put(cur, counter.get(cur) + 1);
    }
}

class Solution {
    
    int M;
    Map<Integer, Integer> blackmap;
    Random r;

    public Solution(int N, int[] blacklist) {
        r = new Random();
        M = N - blacklist.length;
        Arrays.sort(blacklist);
        int num = M;
        int i = 0;
        blackmap = new HashMap<>();
        Set<Integer> blackset = new HashSet<>();
        for(int item : blacklist) blackset.add(item);
        while (num < N) {
            if (!blackset.contains(num)) {
                blackmap.put(blacklist[i++], num);
            }
            ++num;
        }
        // for(int j : blackset) System.out.println(j);
        // for(int key : blackmap.keySet()) {
        //     System.out.println(key + " : " + blackmap.get(key));
        // }
    }
    
    public int pick() {
        int num = r.nextInt(M);
        if (blackmap.containsKey(num)) {
            return blackmap.get(num);
        }
        return num;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

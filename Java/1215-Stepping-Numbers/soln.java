class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        if(low > high) return ans;
        Queue<Long> frontier = new LinkedList<>();
        for(int i = 1; i <= 9; ++i) {
            frontier.add((long) i);
        }
        if(low == 0) ans.add(0);
        while(!frontier.isEmpty()) {
            long num = frontier.poll();
            if (num < high) {
                long d = num % 10;
                if(d > 0) frontier.add(num * 10 + d - 1);
                if(d < 9) frontier.add(num * 10 + d + 1);
            }
            if(low <= num && num <= high) ans.add((int) num);
        }
        return ans;
    }
}

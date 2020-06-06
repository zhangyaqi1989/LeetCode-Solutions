class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Integer> qr = new LinkedList<>();
        Queue<Integer> qd = new LinkedList<>();
        int n = senate.length();
        for(int i = 0; i < n; ++i) {
            if (senate.charAt(i) == 'R') qr.offer(i);
            else qd.offer(i);
        }
        while (!qr.isEmpty() && !qd.isEmpty()) {
            int ir = qr.poll(), id = qd.poll();
            if (ir < id) qr.offer(ir + n);
            else qd.offer(id + n);
        }
        return qr.isEmpty() ? "Dire" : "Radiant";
    }
}

class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        Set<Integer> s = new TreeSet<>();
        s.add(d(p1, p2));
        s.add(d(p1, p3));
        s.add(d(p1, p4));
        s.add(d(p2, p3));
        s.add(d(p2, p4));
        s.add(d(p3, p4));
        return s.size() == 2 && !s.contains(0);
    }
    
    public int d(int[] p, int[] q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
}

public class ZigzagIterator {
    
    public List<Integer> v1, v2;
    public int n1, n2, i1, i2, cnt;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        this.v1 = v1;
        this.v2 = v2;
        n1 = v1.size();
        n2 = v2.size();
        i1 = 0;
        i2 = 0;
        cnt = 0;
    }

    public int next() {
        int val;
        if (cnt % 2 == 0) {
            if (i1 < n1) {
                val = v1.get(i1++);
            } else {
                val = v2.get(i2++);
            }
        } else {
            if (i2 < n2) {
                val = v2.get(i2++);
            } else {
                val = v1.get(i1++);
            }
        }
        ++cnt;
        return val;
    }

    public boolean hasNext() {
        return cnt < (n1 + n2);
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */

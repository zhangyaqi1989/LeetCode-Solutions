class Solution {
    public boolean hasAlternatingBits(int n) {
        ArrayList<Integer> v = new ArrayList<>();
        while(n != 0) {
            v.add(n % 2);
            n /= 2;
        }
        int len = v.size();
        for(int i = 0; i < len - 1; ++i) {
            if(v.get(i) == v.get(i + 1)) return false;
        }
        return true;
    }
}

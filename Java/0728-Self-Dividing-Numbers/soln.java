class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> ans = new ArrayList<>();
        for(int num = left; num <= right; ++num) {
            if (isSelfDivid(num)) ans.add(num);
        }
        return ans;
    }
    
    public boolean isSelfDivid(int num) {
        int n = num;
        while (n > 0) {
            int d = n % 10;
            if (d == 0 || num % d != 0) return false;
            n /= 10;
        }
        return true;
    }
}

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        final int N = 2005;
        int [] counter = new int [N];
        for(int num : arr) ++counter[num + 1000];
        boolean [] seen = new boolean [1001];
        for(int num = 0; num < N; ++num) {
            if(counter[num] == 0) continue;
            if(seen[counter[num]]) return false;
            seen[counter[num]] = true;
        }
        return true;
    }
}

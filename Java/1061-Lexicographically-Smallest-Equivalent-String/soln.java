class Solution {
    private int [] parents;
    public String smallestEquivalentString(String A, String B, String S) {
        parents = new int[26];
        for(int i = 0; i < 26; ++i) parents[i] = i;
        int n = A.length();
        for(int i = 0; i < n; ++i) {
            int x = A.charAt(i) - 'a', y = B.charAt(i) - 'a';
            unite(x, y);
        }
        StringBuilder sb = new StringBuilder();
        for(char ch : S.toCharArray()) {
            sb.append((char)('a' + find(ch - 'a')));
        }
        return sb.toString();
    }
    
    public int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }
    
    public void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx < ry) parents[ry] = parents[rx];
        else parents[rx] = parents[ry];
    }
}

ass Solution {
    public int findLonelyPixel(char[][] picture) {
        Map<String, Integer> records = new HashMap<>();
        int m = picture.length, n = picture[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    records.put("r" + i, records.getOrDefault("r" + i, 0) + 1);
                    records.put("c" + j, records.getOrDefault("c" + j, 0) + 1);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && records.getOrDefault("r" + i, 0) == 1 && records.getOrDefault("c" + j, 0) == 1)
                    ++cnt;
            }
        }
        return cnt;
    }
}

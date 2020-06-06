class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> rows = new ArrayList<>();
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for(int i = 0; i < numRows; ++i) {
            rows.add(row);
            List<Integer> new_row = new ArrayList<>();
            new_row.add(1);
            int m = row.size();
            for(int j = 0; j < m - 1; ++j) new_row.add(row.get(j) + row.get(j + 1));
            new_row.add(1);
            row = new_row;
        }
        return rows;
    }
}

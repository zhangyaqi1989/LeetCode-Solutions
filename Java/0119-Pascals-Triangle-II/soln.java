class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for(int i = 0; i < rowIndex; ++i) {
            List<Integer> temp = new ArrayList<>();
            temp.add(1);
            for(int j = 0; j < row.size() - 1; ++j) {
                temp.add(row.get(j) + row.get(j + 1));
            }
            temp.add(1);
            row = temp;
        }
        return row;
    }
}

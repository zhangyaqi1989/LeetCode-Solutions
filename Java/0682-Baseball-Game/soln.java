class Solution {
    public int calPoints(String[] ops) {
        List<Integer> rounds = new ArrayList<>();
        for(String op : ops) {
            if (op.equals("+")) {
                int a = rounds.get(rounds.size() - 1);
                int b = rounds.get(rounds.size() - 2);
                rounds.add(a + b);
            } else if (op.equals("D")) {
                int a = rounds.get(rounds.size() - 1);
                rounds.add(a * 2);
            } else if (op.equals("C")) {
                rounds.remove(rounds.size() - 1);
            } else {
                rounds.add(Integer.parseInt(op));
            }
        }
        int ans = 0;
        for(int score : rounds) ans += score;
        return ans;
    }
}

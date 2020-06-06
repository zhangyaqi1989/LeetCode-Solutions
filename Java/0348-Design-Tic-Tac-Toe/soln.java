class TicTacToe {
    
    public int n;
    public Map<String, Integer> player1;
    public Map<String, Integer> player2;

    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        this.n = n;
        player1 = new HashMap<>();
        player2 = new HashMap<>();
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        Map<String, Integer> counter;
        if (player == 1) counter = player1;
        else counter = player2;
        for(int [] condition : new int [][] {{1, row}, {2, col}, {3, row + col}, {4, row - col}}) {
            String key = Integer.toString(condition[0]) + "-" + Integer.toString(condition[1]);
            // System.out.println(counter.containsKey(key));
            counter.put(key, counter.getOrDefault(key, 0) + 1);
            // System.out.println(counter.get(condition));
            if (counter.get(key) == n) return player;
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

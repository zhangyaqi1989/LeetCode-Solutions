class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        map<tuple<int, int, int>, int> board;
        const int kN = moves.size();
        for(int i = 0; i < kN; ++i) {
            int player = i % 2;
            int r = moves[i][0], c = moves[i][1];
            if (++board[{player, 0, r}] == 3) return player == 0 ? "A" : "B";
            if (++board[{player, 1, c}] == 3) return player == 0 ? "A" : "B";
            if (++board[{player, 2, r + c}] == 3) return player == 0 ? "A" : "B";
            if (++board[{player, 3, r - c}] == 3) return player == 0 ? "A" : "B";
        }
        return kN == 9 ? "Draw" : "Pending";
    }
};

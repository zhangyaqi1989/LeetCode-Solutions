class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, vector<string>> fulls;
        int n = words[0].length();
        for(string word : words) {
            for(int i = 1; i < n; ++i) {
                fulls[word.substr(0, i)].push_back(word);
            }
        }
        vector<vector<string>> squares;
        vector<string> square;
        for(string word : words) {
            square.push_back(word);
            build(square, squares, fulls, n);
            square.pop_back();
        }
        return squares;
    }
    
private:
    void build(vector<string> & square, vector<vector<string>> & squares, unordered_map<string, vector<string>> & fulls, int n) {
        if (square.size() == n) {
            squares.push_back(square);
        } else {
            string nxt = "";
            for(string w : square) {
                nxt += w[square.size()];
            }
            for(string word : fulls[nxt]) {
                square.push_back(word);
                build(square, squares, fulls, n);
                square.pop_back();
            }
        }
    }
};

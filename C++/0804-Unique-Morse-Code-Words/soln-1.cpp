class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> codes;
        for(string word : words) {
            string code = "";
            for(char ch : word) code += d[ch - 'a'];
            codes.insert(code);
        }
        return codes.size();
    }
};

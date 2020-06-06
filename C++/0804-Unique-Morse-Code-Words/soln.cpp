class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string chrs[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (auto & word : words) {
            string temp = "";
            for (char ch : word)
                temp += chrs[ch - 'a'];
            s.insert(temp);
        }
        return s.size();
    }
};
class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0) return;
        istringstream iss(s);
        string result = "";
        string w;
        while(iss >> w)
            result.insert(0, w + ' ');
        if(result.size() > 0) result.pop_back();
        s = result;
    }
};
class Solution {
public:
    int shortestWay(string source, string target) {
        int chars[26] = {0};
        for(char ch : source) ++chars[ch - 'a'];
        if (any_of(target.begin(), target.end(), [&](char ch) {return chars[ch - 'a'] == 0;})) return -1;
        const int ns = source.length(), nt = target.length();
        int cnt = 0;
        int j = 0;
        while (j < nt)
            if(source[cnt++ % ns] == target[j]) ++j;
        return (cnt + ns - 1) / ns;
    }
};

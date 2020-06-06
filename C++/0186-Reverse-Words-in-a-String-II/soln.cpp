class Solution {
public:
    void reverseWords(vector<char>& str) {
        vector<char>::iterator iptr = str.begin();
        for(auto jptr = str.begin(); jptr != str.end(); ++jptr)
        {
            if(*jptr == ' ')
            {
                reverse(iptr, jptr);
                iptr = jptr + 1;
            }
        }
        reverse(iptr, str.end());
        reverse(str.begin(), str.end());
    }
};
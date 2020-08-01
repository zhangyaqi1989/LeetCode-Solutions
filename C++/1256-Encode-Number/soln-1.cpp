class Solution {
public:
    string encode(int num) {
        if(num == 0) return "";
        return encode((num - 1) / 2) + (num % 2 == 1 ? "0" : "1");
    }
};

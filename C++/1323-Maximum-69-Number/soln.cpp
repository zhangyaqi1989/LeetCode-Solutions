class Solution {
public:
    int maximum69Number (int num) {
        int last = -1;
        int i = 0;
        int old_num = num;
        while (num) {
            if (num % 10 == 6) {
                last = i;
            }
            ++i;
            num /= 10;
        }
        return (last == -1) ? old_num : (old_num + 3 * pow(10, last)); 
    }
};

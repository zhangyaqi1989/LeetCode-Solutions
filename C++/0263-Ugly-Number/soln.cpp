class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        for (auto factor : {2, 3, 5})
            while (num % factor == 0)
                num /= factor;
        return num == 1;
    }
};
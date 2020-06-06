// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int idx = (rand7() - 1) * 7 + (rand7() - 1);
            if (idx < 40) return idx % 10 + 1;
        }
    }
};

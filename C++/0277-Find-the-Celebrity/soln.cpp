// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (i == ans) continue;
            if (!knows(i, ans) || knows(ans, i)) {
                valid = false;
                break;
            }
        }
        return valid ? ans : -1;
    }
};

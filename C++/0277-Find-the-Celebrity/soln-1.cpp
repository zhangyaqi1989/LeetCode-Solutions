// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // all other n - 1 people know him, he does not know any of them
        int celebrity = 0;
        for(int i = 1; i < n; ++i) {
            if (!knows(i, celebrity)) {
                celebrity = i;
            }
        }
        int valid = true;
        for(int i = 0; i < n; ++i) {
            if (i == celebrity) continue;
            if (knows(celebrity, i) || !knows(i, celebrity)) {
                valid = false;
                break;
            }
        }
        return valid ? celebrity : -1;
    }
};

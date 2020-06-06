/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity(int n) {
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            if (knows(ans, i)) {
                ans = i;
            }
        }
        boolean valid = true;
        for(int i = 0; i < n; ++i) {
            if (i == ans) continue;
            if (knows(ans, i) || !knows(i, ans)) {
                valid = false;
                break;
            }
        }
        return valid ? ans : -1;
    }
}

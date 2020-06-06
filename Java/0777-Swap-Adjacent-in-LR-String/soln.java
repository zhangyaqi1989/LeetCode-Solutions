class Solution {
    public boolean canTransform(String a, String b) {
        // XL -> LX
        // RX -> XR
        // L can never cross R
        int ia = 0, ib = 0, n = a.length();
        while (true) {
            while (ia < n && a.charAt(ia) == 'X') ++ia;
            while (ib < n && b.charAt(ib) == 'X') ++ib;
            if (ia == n && ib == n) break;
            else if (ia < n && ib < n) {
                if (a.charAt(ia) != b.charAt(ib) || (a.charAt(ia) == 'L' && ia < ib) || (a.charAt(ia) == 'R' && ia > ib)) 
                    return false;
            } else {
                return false;
            }
            ++ia;
            ++ib;
        }
        return true;
    }
}

class Solution {
    public int findLUSlength(String a, String b) {
        int na = a.length(), nb = b.length();
        if (na != nb) {
            return na < nb ? nb : na;
        } else {
            if (!a.equals(b)) return na;
            return -1;
        }
    }
}

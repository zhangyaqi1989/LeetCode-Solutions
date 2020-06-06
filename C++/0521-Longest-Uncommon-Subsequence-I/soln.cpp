class Solution {
public:
    int findLUSlength(string a, string b) {
        int na = a.length(), nb = b.length();
        if (na != nb) {
            return na < nb ? nb : na;
        } else {
            if (a != b) return na;
            return -1;
        }
    }
};

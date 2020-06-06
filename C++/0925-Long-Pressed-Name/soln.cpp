class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        name += "#";
        typed += "#";
        int curn = 0, curt = 0;
        int nn = name.length(), nt = typed.length();
        int lon = 0, lot = 0;
        while (curn < nn && curt < nt) {
            while (curn < nn && name[curn] == name[lon]) {
                ++curn;
            }
            while (curt < nt && typed[curt] == typed[lot]) {
                ++curt;
            }
            if (curn >= nn || curt >= nt) break;
            if (name[lon] != typed[lot] || curt - lot < curn - lon) return false;
            lon = curn;
            lot = curt;
        }
        // cout << curn << " " << curt << endl;
        return name[curn - 1] == '#' && typed[curt - 1] == '#';
    }
};

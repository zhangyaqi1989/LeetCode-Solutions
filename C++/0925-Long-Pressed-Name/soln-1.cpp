class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int na = name.length(), nb = typed.length();
        int ia = 0, ib = 0, ja = 0, jb = 0;
        while (ja < na && jb < nb) {
            while (ja < na && name[ja] == name[ia]) ++ja;
            while (jb < nb && typed[jb] == typed[ib]) ++jb;
            if (name[ia] != typed[ib] || jb - ib < ja - ia) return false;
            ia = ja;
            ib = jb;
        }
        return ja == na && jb == nb && name[ia] == typed[ib] && nb - ib >= na - ia;
    }
};

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> s;
        s.insert(distance2(p1, p2));
        s.insert(distance2(p1, p3));
        s.insert(distance2(p1, p4));
        s.insert(distance2(p2, p3));
        s.insert(distance2(p2, p4));
        s.insert(distance2(p3, p4));
        return s.size() == 2 && (*s.rbegin()) == 2 * (*s.begin());
    }
    
    int distance2(vector<int>& p, vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }
};

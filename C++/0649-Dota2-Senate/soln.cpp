class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        int n = senate.length();
        for(int i = 0; i < n; ++i) {
            if (senate[i] == 'R') qr.push(i);
            else qd.push(i);
        }
        while (!qr.empty() && !qd.empty()) {
            int ir = qr.front(), id = qd.front();
            qr.pop();
            qd.pop();
            if (ir < id) qr.push(ir + n);
            else qd.push(id + n);
        }
        return qr.empty() ? "Dire" : "Radiant";        
    }
};

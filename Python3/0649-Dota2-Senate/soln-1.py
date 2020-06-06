class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        qr = collections.deque()
        qd = collections.deque()
        for i, ch in enumerate(senate):
            if ch == 'R':
                qr.append(i)
            else:
                qd.append(i)
        n = len(senate)
        while qr and qd:
            ri, di = qr.popleft(), qd.popleft()
            if ri < di:
                qr.append(ri + n)
            else:
                qd.append(di + n)
        return "Radiant" if qr else "Dire"

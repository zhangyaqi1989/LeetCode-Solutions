class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        if len(croakOfFrogs) % 5 != 0:
            return -1
        counter = collections.Counter()
        mx = 0
        s = "croak"
        idxes = {'r' : 1, 'o' : 2, 'a' : 3, 'k' : 4}
        for ch in croakOfFrogs:
            counter[ch] += 1
            if ch != 'c' and any(counter[ch] > counter[s[i]] for i in range(idxes[ch])):
                return -1
            if len(counter) == 5 and counter['k'] == 1:
                for c in s:
                    counter[c] -= 1
                    if counter[c] == 0:
                        counter.pop(c)
            if counter:
                mx = max(mx, max(counter.values()))
        return mx if not counter else -1

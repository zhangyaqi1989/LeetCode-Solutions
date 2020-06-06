class Solution:
    def numSquarefulPerms(self, A: 'List[int]') -> 'int':
        counter = collections.Counter(A)
        def valid(a, b):
            root = int(math.sqrt(a + b))
            return root * root == a + b
        cands = collections.defaultdict(list)
        for a in counter:
            for b in counter:
                if valid(a, b):
                    cands[a].append(b)
        self.ans = 0
        def helper(cur, left=len(A) - 1):
            if left == 0:
                self.ans += 1
                return
            counter[cur] -= 1
            for cand in cands[cur]:
                if counter[cand]:
                    helper(cand, left - 1)
            counter[cur] += 1
        for c in counter:
            helper(c)
        return self.ans

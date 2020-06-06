class Solution:
    def generatePalindromes(self, s: str) -> List[str]:
        counter = collections.Counter(s)
        odds = sum(cnt % 2 for cnt in counter.values())
        if odds > 1:
            return []
        if odds == 1:
            mid = next(ch for ch, cnt in counter.items() if cnt % 2 == 1)
        else:
            mid = ''
        half_digits = ''.join(ch * (cnt // 2)  for ch, cnt in counter.items())
        # permutation with duplicates
        permus = self.permutation(list(half_digits))
        return [''.join(permu + [mid] + permu[::-1]) for permu in permus]
        
    def permutation(self, chs : List[str]) -> List[List[str]]:
        "compute the permutation of lst"
        ans = [[]]
        for ch in chs:
            temp = []
            for lst in ans:
                for i in range(len(lst) + 1):
                    if i > 0 and lst[i - 1] == ch:
                        break
                    clst = lst[:]
                    clst.insert(i, ch)
                    temp.append(clst)
            ans = temp
        return ans

class Solution:
    def expand(self, S: str) -> List[str]:
        blocks = S.replace('{', ' ').replace('}', ' ').split()
        blocks = [b.split(',') for b in blocks]
        return sorted([''.join(lst) for lst in itertools.product(*blocks)])

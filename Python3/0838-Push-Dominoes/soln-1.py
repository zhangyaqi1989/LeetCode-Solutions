class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        leftRs = []
        left_R = None
        n = len(dominoes)
        ans = [None] * n
        for i, d in enumerate(dominoes):
            if d == 'R':
                left_R = 0
                ans[i] = 'R'
            elif d == 'L':
                left_R = None
                ans[i] = 'L'
            else:
                if left_R is not None:
                    left_R += 1
                    ans[i] = 'R'
                else:
                    ans[i] = '.'
            leftRs.append(left_R)
        right_L = None
        for i in reversed(range(n)):
            d = dominoes[i]
            if d == 'L':
                right_L = 0
                ans[i] = 'L'
            elif d == 'R':
                right_L = None
                ans[i] = 'R'
            else:
                if right_L is not None:
                    right_L += 1
                    if leftRs[i] is None:
                        ans[i] = 'L'
                    else:
                        if leftRs[i] < right_L:
                            ans[i] = 'R'
                        elif leftRs[i] == right_L:
                            ans[i] = '.'
                        else:
                            ans[i] = 'L'
                else:
                    if leftRs[i] is not None:
                        ans[i] = 'R'
                    else:
                        ans[i] = '.'
        return ''.join(ans)

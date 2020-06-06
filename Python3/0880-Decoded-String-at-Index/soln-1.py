class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        N = 0
        for i in range(len(S)):
            if S[i].isdigit():
                N = N * int(S[i])
            else:
                N += 1
            if N >= K:
                break
        for j in range(i, -1, -1):
            if S[j].isdigit():
                N //= int(S[j])
                K %= N
            else:
                if K % N == 0:
                    return S[j]
                else:
                    N -= 1

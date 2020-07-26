class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        # "aaabcccd"
        n = len(s)
        dp = [[{} for _ in range(k + 1)] for _ in range(n + 1)]
        dp[0][0][""] = 0
        for i in range(1, n + 1):
            ch = s[i - 1]
            for j in range(0, min(i + 1, k + 1)):
                # dp[i][j][?] is related to dp[i - 1][j/j-1][?]
                if j == 0:
                    # dp[i - 1][0][""]
                    for left, cnt in dp[i - 1][0].items():
                        if left == "":
                            dp[i][0][ch] = cnt + 1
                        elif len(left) == 1:
                            if left[0] == ch:
                                dp[i][0][f"{ch}2"] = cnt + 1
                            else:
                                dp[i][0][f"{ch}"] = cnt + 1
                        else:
                            pre, num = left[0], int(left[1:])
                            if pre == ch:
                                dp[i][0][f"{ch}{num + 1}"] = cnt + len(f"{num + 1}") - (len(left) - 1)
                            else:
                                dp[i][0][f"{ch}"] = cnt + 1
                else: # j > 0
                    for left, cnt in dp[i - 1][j - 1].items():
                        dp[i][j][left] = cnt
                    for left, cnt in dp[i - 1][j].items():
                        if left == "":
                            dp[i][j][ch] = min(dp[i][j].get(ch, math.inf), cnt + 1)
                        elif len(left) == 1:
                            if left[0] == ch:
                                dp[i][j][f"{ch}2"] = min(dp[i][j].get(f"{ch}2", math.inf), cnt + 1)
                            else:
                                dp[i][j][f"{ch}"] = min(dp[i][j].get(f"{ch}", math.inf), cnt + 1)
                        else:
                            pre, num = left[0], int(left[1:])
                            if pre == ch:
                                dp[i][j][f"{ch}{num + 1}"] = min(dp[i][j].get(f"{ch}{num + 1}", math.inf), cnt + len(f"{num + 1}") - (len(left) - 1))
                            else:
                                dp[i][j][f"{ch}"] = min(dp[i][j].get(f"{ch}", math.inf), cnt + 1)
                # print(i, j, dp[i][j])
        best = n
        for j in range(0, k + 1):
            best = min(best, min(dp[n][j].values()))
        return best

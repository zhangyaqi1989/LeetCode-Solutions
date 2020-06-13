class Solution:
    def countLargestGroup(self, n: int) -> int:
        digit_sums = [sum(map(int, str(val))) for val in range(1, n + 1)]
        counter = collections.Counter(digit_sums)
        mx = counter.most_common(1)[0][1]
        return sum(cnt == mx for cnt in counter.values())

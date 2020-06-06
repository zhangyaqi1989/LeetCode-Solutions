class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        scores = collections.defaultdict(list)
        for i, score in items:
            scores[i].append(score)
        ans = []
        for i in sorted(scores):
            avg = sum(heapq.nlargest(5, scores[i])) // 5
            ans.append([i, avg])
        return ans

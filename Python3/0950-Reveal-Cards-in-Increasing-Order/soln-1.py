class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        n = len(deck)
        order = collections.deque(list(range(n)))
        m = [-1] * n
        cnt = 0
        while order:
            idx = order.popleft()
            m[cnt] = idx
            cnt += 1
            if order:
                order.append(order.popleft())
        deck.sort()
        ans = [0] * n
        for i, idx in enumerate(m):
            ans[idx] = deck[i]
        return ans

class Solution:
    def isHappy(self, n: int) -> bool:
        func = lambda x : sum(int(ch) ** 2 for ch in str(x))
        slow = func(n);
        fast = func(func(n));
        while slow != fast:
            slow = func(slow)
            fast = func(func(fast))
        if slow == 1:
            return True
        else:
            return False

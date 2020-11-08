class Solution:
    def maxProfit(self, inventory: List[int], orders: int) -> int:
        # [5, 5, 2]
        inventory.sort(reverse=True)
        inventory.append(0)
        ans = 0
        idx = 0
        n = len(inventory)
        while orders:
            # find the first index such that inv[j] < inv[i]
            lo, hi = idx + 1, n - 1
            while lo < hi:
                mid = (lo + hi) // 2
                if inventory[mid] == inventory[idx]:
                    lo = mid + 1
                else:
                    hi = mid
            if lo >= n:
                break
            mult = lo
            if mult * (inventory[idx] - inventory[lo]) >= orders:
            # from inventory[idx] to inventory[lo]
                q, r = divmod(orders, mult)
                ans += mult * (inventory[idx] + inventory[idx] - q + 1) * q // 2 
                ans += r * (inventory[idx] - q)
                orders = 0
            else:
                orders -= mult * (inventory[idx] - inventory[lo])
                ans += mult * (inventory[idx] + inventory[lo] + 1) * (inventory[idx] - inventory[lo]) // 2
            idx = lo
            ans %= 1_000_000_007
        return ans

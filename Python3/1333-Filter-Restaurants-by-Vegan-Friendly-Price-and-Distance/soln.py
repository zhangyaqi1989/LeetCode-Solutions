class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        # [idi, ratingi, veganFriendlyi, pricei, distancei]
        ans = []
        for idx, r, v, p, d in restaurants:
            if veganFriendly == 1 and v == 0:
                continue
            if p <= maxPrice and d <= maxDistance:
                ans.append([-r, -idx])
        return [-i for _, i in sorted(ans)]

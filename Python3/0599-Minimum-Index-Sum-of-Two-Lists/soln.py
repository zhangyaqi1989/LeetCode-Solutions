class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        d1 = {name : i for i, name in enumerate(list1)}
        d2 = {name : i for i, name in enumerate(list2)}
        ans, mn_idx = [], math.inf
        for name in set(list1) & set(list2):
            idx = d1[name] + d2[name]
            if idx < mn_idx:
                mn_idx = idx
                ans = [name]
            elif idx == mn_idx:
                ans.append(name)
        return ans

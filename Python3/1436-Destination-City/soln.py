class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        bads = set()
        cities = set()
        for u, v in paths:
            cities.add(u)
            cities.add(v)
            bads.add(u)
        ans = cities - bads
        return list(ans)[0]

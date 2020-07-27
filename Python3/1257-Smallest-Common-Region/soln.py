class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        parents = {}
        for parent, *children in regions:
            for child in children:
                parents[child] = parent
        cands = set()
        while region1:
            cands.add(region1)
            region1 = parents.get(region1, None)
        while region2:
            if region2 in cands:
                return region2
            region2 = parents.get(region2, None)
        return None

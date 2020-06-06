class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        # build a map from content to list of paths
        d = collections.defaultdict(list)
        for path in paths:
            parent, *files = path.split()
            for item in files:
                idx = item.rfind('(')
                name = item[:idx]
                content = item[idx + 1:-1]
                d[content].append(parent + '/' + name)
        return [lst for lst in d.values() if len(lst) > 1]

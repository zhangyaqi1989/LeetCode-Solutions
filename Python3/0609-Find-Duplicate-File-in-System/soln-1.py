class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        ans = collections.defaultdict(list)
        for path in paths:
            dir_path, *files = path.split()
            dir_path += '/'
            for file in files:
                idx = file.index('(')
                ans[file[idx:-1]].append(dir_path + file[:idx])
        return list(filter(lambda x : len(x) > 1, ans.values()))
class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        ans = collections.defaultdict(list)
        for path in paths:
            dir_path, *files = path.split()
            for file in files:
                idx = file.index('(')
                content = file[idx:-1]
                file_path = dir_path + '/' + file[:idx]
                ans[content].append(file_path)
        return list(value for value in ans.values() if len(value) > 1)
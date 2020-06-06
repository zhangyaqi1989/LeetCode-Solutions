class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        letters, digits = [], []
        for log in logs:
            identifier, rest = log.split(' ', 1)
            if all(ch.isdigit() for ch in rest if ch != ' '):
                digits.append(log)
            else:
                letters.append((rest, identifier, log))
        letters.sort()
        return [log for _, _, log in letters] + digits
class Solution:
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        return list(filter(None, re.sub(r'//.*|/\*(.|\n)*?\*/', '', '\n'.join(source)).split('\n')))
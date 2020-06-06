class Solution:
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        return [item for item in re.sub(r'//.*|/\*(.|\n)*?\*/', '', '\n'.join(source)).split('\n') if item]
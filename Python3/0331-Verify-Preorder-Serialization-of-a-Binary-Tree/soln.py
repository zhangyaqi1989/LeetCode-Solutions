class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        data = iter(preorder.split(','))
        def valid():
            val = next(data, None)
            if val is not None:
                if val == '#':
                    pass
                else:
                    return valid() and valid()
                return True
            else:
                return False
        return valid() and next(data, None) is None

class Solution:
    def removeDuplicates(self, S: str) -> str:
        def process(S):
            lst = []
            for key, g in itertools.groupby(S):
                n = len(list(g))
                if n % 2:
                    lst.append(key)
            return lst
        S_lst = list(S)
        while True:
            new_lst = process(S_lst)
            if len(new_lst) == len(S_lst):
                break
            S_lst = new_lst
        return ''.join(S_lst)
        

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        counter = collections.Counter(arr)
        values = list(counter.values())
        return len(set(values)) == len(values)

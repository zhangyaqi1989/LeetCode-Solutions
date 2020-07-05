class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.combs = [''.join(combo) for combo in itertools.combinations(characters, combinationLength)]
        self.combs.sort(reverse=True)

    def next(self) -> str:
        return self.combs.pop()

    def hasNext(self) -> bool:
        return len(self.combs) != 0

# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()

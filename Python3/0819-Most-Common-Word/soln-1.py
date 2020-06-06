class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        banset = set(banned)
        return collections.Counter([w for w in re.findall(r'\w+', paragraph.lower()) if w not in banset]).most_common(1)[0][0]

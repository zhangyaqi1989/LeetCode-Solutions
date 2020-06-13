class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_counter = [0] * 26
        for ch in chars:
            chars_counter[ord(ch) - ord('a')] += 1
        def can_form(word):
            counter = [0] * 26
            for ch in word:
                counter[ord(ch) - ord('a')] += 1
            return all(chars_counter[i] >= counter[i] for i in range(26))
        return sum(len(w) for w in words if can_form(w))

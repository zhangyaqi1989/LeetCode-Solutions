class Solution:
    def removeVowels(self, S: str) -> str:
        vowels = "aeiou"
        return ''.join((ch if ch not in vowels else "") for ch in S)

class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        plate = [ch.lower() for ch in licensePlate if ch.isalpha()]
        plate = collections.Counter(plate)
        def valid(word):
            "Check if a word is a completing word."
            counts = collections.Counter(word)
            return all(counts[ch] >= cnt for ch, cnt in plate.items())
        for word in sorted(words, key=len):
            if valid(word):
                return word

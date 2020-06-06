class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        ws = text.split()
        return [ws[i + 2] for i in range(len(ws) - 2) if ws[i] == first and ws[i + 1] == second]

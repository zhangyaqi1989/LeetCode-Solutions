class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def is_letter_log(log):
            word = log[log.rfind(" ") + 1:]
            return word.isalpha()
        return sorted([log for log in logs if is_letter_log(log)], key=lambda x : (x[x.find(" ") + 1:], x[0:x.find(" ")])) + [log for log in logs if not is_letter_log(log)]

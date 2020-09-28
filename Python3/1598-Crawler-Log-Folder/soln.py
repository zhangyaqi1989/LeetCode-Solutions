class Solution:
    def minOperations(self, logs: List[str]) -> int:
        folder_stack = []
        for command in logs:
            if command.startswith('..'):
                if folder_stack:
                    folder_stack.pop()
            else:
                if command.startswith('.'):
                    continue
                folder_stack.append(None)
        return len(folder_stack)

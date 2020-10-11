# Definition for a binary tree node.
# class Node(object):
#     def __init__(self, val=" ", left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def expTree(self, s: str) -> 'Node':
        def process_op():
            op = op_stack.pop()
            rhs = val_stack.pop()
            lhs = val_stack.pop()
            node = Node(val=op, left=lhs, right=rhs)
            val_stack.append(node)
        def priority(op):
            if op in '+-':
                return 1
            elif op in '*/':
                return 2
            else:
                return -1
        val_stack = []
        op_stack = []
        for ch in s:
            if ch.isdigit():
                val_stack.append(Node(ch))
            else:
                if ch == '(':
                    op_stack.append('(')
                elif ch == ')':
                    while op_stack[-1] != '(':
                        process_op()
                    op_stack.pop()
                else:
                    cur_op = ch
                    while op_stack and priority(op_stack[-1]) >= priority(cur_op):
                        process_op()
                    op_stack.append(cur_op)
        while op_stack:
            process_op()
        return val_stack[0]

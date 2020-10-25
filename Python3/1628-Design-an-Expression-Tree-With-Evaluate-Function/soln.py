import abc 
from abc import ABC, abstractmethod
import operator
"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""

class Node(ABC):
    @abstractmethod
    # define your fields here
    def evaluate(self) -> int:
        pass
    
class BNode(Node):
    OP_TO_FUNC = {'+': operator.add,
                  '-': operator.sub,
                  '*': operator.mul,
                  '/': operator.floordiv,
                 }
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
    def evaluate(self) -> int:
        func = self.OP_TO_FUNC.get(self.val, None)
        if func is not None:
            return func(self.left.evaluate(), self.right.evaluate())
        else:
            return int(self.val)


"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""

class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        stack = []
        for item in postfix:
            if item in '+-*/':
                rhs = stack.pop()
                lhs = stack.pop()
                node = BNode(item, lhs, rhs)
                stack.append(node)
            else:
                stack.append(BNode(item))
        return stack[0]
                
        
"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
        

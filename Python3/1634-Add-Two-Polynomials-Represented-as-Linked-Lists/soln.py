# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        counter = collections.Counter()
        while poly1:
            counter[poly1.power] += poly1.coefficient
            poly1 = poly1.next
        while poly2:
            counter[poly2.power] += poly2.coefficient
            poly2 = poly2.next
        dummy = PolyNode()
        cur = dummy
        for power in sorted(counter, reverse=True):
            coeff = counter[power]
            if coeff:
                new_node = PolyNode(x=counter[power], y=power)
                cur.next = new_node
                cur = cur.next
        return dummy.next

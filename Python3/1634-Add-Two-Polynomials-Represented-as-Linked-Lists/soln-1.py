# Definition for polynomial singly-linked list.
# class PolyNode:
#     def __init__(self, x=0, y=0, next=None):
#         self.coefficient = x
#         self.power = y
#         self.next = next

class Solution:
    def addPoly(self, poly1: 'PolyNode', poly2: 'PolyNode') -> 'PolyNode':
        dummy = PolyNode()
        cur = dummy
        while poly1 and poly2:
            if poly1.power > poly2.power:
                power = poly1.power
                coeff = poly1.coefficient
                poly1 = poly1.next
            elif poly1.power == poly2.power:
                power = poly1.power
                coeff = poly1.coefficient + poly2.coefficient
                poly1 = poly1.next
                poly2 = poly2.next
            else:
                power = poly2.power
                coeff = poly2.coefficient
                poly2 = poly2.next
            if coeff:
                cur.next = PolyNode(coeff, power)
                cur = cur.next
        cur.next = poly1 or poly2
        return dummy.next

class ListNode:
    
    def __init__(self, val):
        self.val = val
        self.next = None


class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.size = 0
        

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        # cur = self.head
        # while cur:
        #     print(cur.val, end=' ')
        #     cur = cur.next
        # print()
        if 0 <= index < self.size:
            cur = self.head
            for _ in range(index):
                cur = cur.next
            return cur.val
        else:
            return -1
        

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: void
        """
        node = ListNode(val)
        self.size += 1
        node.next = self.head
        self.head = node
        

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: void
        """
        node = ListNode(val)
        if self.size == 0:
            self.head = node
        else:
            cur = self.head
            for _ in range(self.size - 1):
                cur = cur.next
            cur.next = node
        self.size += 1
        

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: void
        """
        if 0 <= index <= self.size:
            if index == 0:
                self.addAtHead(val)
            elif index == self.size:
                self.addAtTail(val)
            else:
                self.size += 1
                cur = self.head
                node = ListNode(val)
                for _ in range(index - 1):
                    cur = cur.next
                node.next = cur.next
                cur.next = node

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: void
        """
        if 0 <= index < self.size:
            if index == 0:
                self.head = self.head.next
            else:
                cur = self.head
                for _ in range(index - 1):
                    cur = cur.next
                cur.next = cur.next.next
            self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)

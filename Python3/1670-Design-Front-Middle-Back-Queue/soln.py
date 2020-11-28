class FrontMiddleBackQueue:
    # Two deque
    # First deque is longer than second deque
    # len(F) - len(S) <= 1

    def __init__(self):
        self._first = collections.deque()
        self._second = collections.deque()

    def _balance(self):
        if len(self._second) > len(self._first):
            self._first.append(self._second.popleft())
        if len(self._first) - len(self._second) >= 2:
            self._second.appendleft(self._first.pop())

    def pushFront(self, val: int) -> None:
        self._first.appendleft(val)
        self._balance()

    def pushMiddle(self, val: int) -> None:
        if len(self._first) == len(self._second):
            self._first.append(val)
        else:
            last = self._first.pop()
            self._first.append(val)
            self._first.append(last)
        self._balance()

    def pushBack(self, val: int) -> None:
        self._second.append(val)
        self._balance()
        
    def popFront(self) -> int:
        if not self._first:
            return -1
        val = self._first.popleft()
        self._balance()
        return val
    
    def popMiddle(self) -> int:
        if not self._first:
            return -1
        val = self._first.pop()
        self._balance()
        return val

    def popBack(self) -> int:
        if not self._first:
            return -1
        val = self._second.pop() if self._second else self._first.pop()
        self._balance()
        return val

# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()

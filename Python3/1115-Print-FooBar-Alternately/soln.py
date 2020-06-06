import threading
class FooBar:
    def __init__(self, n):
        self.n = n
        self.lock1 = threading.Lock()
        self.lock2 = threading.Lock()
        self.lock1.acquire()


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.lock2.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.lock1.release()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            
            # printBar() outputs "bar". Do not change or remove this line.
            self.lock1.acquire()
            printBar()
            self.lock2.release()

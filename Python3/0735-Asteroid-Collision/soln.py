class Solution:
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        lst = []
        for size in asteroids:
            if size > 0:
                lst.append(size)
            else:
                # size < 0
                while lst and lst[-1] > 0:
                    if lst[-1] + size > 0:
                        break
                    elif lst[-1] + size == 0:
                        lst.pop()
                        break
                    else:
                        lst.pop()
                else:
                    lst.append(size)
        return lst

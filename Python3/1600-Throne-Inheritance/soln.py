class ThroneInheritance:

    def __init__(self, kingName: str):
        self._king = kingName
        self._graph = collections.defaultdict(list)
        self._deads = set()

    def birth(self, parentName: str, childName: str) -> None:
        self._graph[parentName].append(childName)

    def death(self, name: str) -> None:
        self._deads.add(name)

    def getInheritanceOrder(self) -> List[str]:
        def preorder(node):
            if node not in self._deads:
                ans.append(node)
            for child in self._graph[node]:
                preorder(child)
        ans = []
        preorder(self._king)
        return ans


# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()

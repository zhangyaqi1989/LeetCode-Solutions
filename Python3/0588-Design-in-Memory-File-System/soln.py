class FileNode:
    
    def __init__(self):
        self.is_file = False
        self.content = ''
        self.children = collections.defaultdict(FileNode) # map name to childNode

class FileSystem:

    def __init__(self):
        self.root = FileNode()
        
        
    def _walk(self, path):
        "walk through the path and return the parent dir and the child name."
        i = 1
        cur_path = '/'
        cur = self.root
        while i < len(path):
            j = path.find('/', i)
            if j != -1:
                name = path[i:j]
                cur = cur.children[name]
                i = j + 1
            else:
                break
        return cur, path[i:]
                    
        

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        cur, name = self._walk(path)
        if name:
            cur = cur.children[name]
        if cur.is_file:
            return [name]
        else:
            return sorted(cur.children.keys())
        
        

    def mkdir(self, path):
        """
        :type path: str
        :rtype: void
        """
        cur, name = self._walk(path)
        # print(name)
        cur = cur.children[name]
        
        

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: void
        """
        cur, name = self._walk(filePath)
        cur.children[name].content += content
        cur.children[name].is_file = True
        

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        cur, name = self._walk(filePath)
        return cur.children[name].content
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)

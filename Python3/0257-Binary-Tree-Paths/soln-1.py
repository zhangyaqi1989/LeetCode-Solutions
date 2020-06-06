 def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        paths = []
        def traverse(node, path):
            if node:
                if not node.left and not node.right:
                    paths.append(path + [node.val])
                else:
                    traverse(node.left, path + [node.val])
                    traverse(node.right, path + [node.val])
        traverse(root, [])
        return ['->'.join(map(str, path)) for path in paths]
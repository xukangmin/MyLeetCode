class TreeNode:
    def __init__(self, val = 0, left = None, right = None) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        pass

    def buildTree(self, preorder : list[int], inorder : list[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        
        v = preorder[0]
        root = TreeNode(val = v)
        i = inorder.index(v)
        root.left = self.buildTree(preorder[1:1+i], inorder[:i])
        root.right = self.buildTree(preorder[1+i:],inorder[1+i:])
        return root



preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]


s = Solution()

tree = s.buildTree(preorder,inorder)

print(tree)
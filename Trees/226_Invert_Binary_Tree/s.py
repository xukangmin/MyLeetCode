# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        

        def dfs(r: TreeNode) -> TreeNode:

            if r == None:
                return None

            left = dfs(r.left)
            right = dfs(r.right)
        
            r.left = right

            r.right = left

            return r
            
        r = dfs(root)

        return r


root = TreeNode(25)

root.left = TreeNode(15)

root.left.left = TreeNode(10)

root.left.left.left = TreeNode(4)

root.left.left.right = TreeNode(12)

root.left.right = TreeNode(22)

root.left.right.left = TreeNode(18)

root.left.right.right = TreeNode(24)



root.right = TreeNode(50)

root.right.left = TreeNode(35)

root.right.left.left = TreeNode(31)

root.right.left.right = TreeNode(44)


root.right.right = TreeNode(70)

root.right.right.left = TreeNode(66)

root.right.right.right = TreeNode(90)



s = Solution()

arr = s.invertTree(root)

print(arr)

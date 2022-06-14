# Definition for a binary tree node.
from glob import glob


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def maxPathSum(self, root: TreeNode) -> int:
        ans = float('-inf')

        def dfs(node: TreeNode) -> int:
            if node == None:
                return 0
            
            left_val = max(0, dfs(node.left))
            right_val = max(0, dfs(node.right))
            nonlocal ans
            ans = max(ans, left_val + right_val + node.val)
            print(ans)

            return max(left_val,right_val) + node.val

        dfs(root)
        return ans



# root = TreeNode(30)

# root.left = TreeNode(9)

# root.right = TreeNode(20)

# root.right.left = TreeNode(15)

# root.right.right = TreeNode(7)


root = TreeNode(25)

root.left = TreeNode(15)

root.right = TreeNode(50)


s = Solution()

sum = s.maxPathSum(root)

print(sum)
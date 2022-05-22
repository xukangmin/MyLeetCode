class TreeNode:
    def __init__(self, val = 0, left = None, right = None) -> None:
        self.val = val
        self.left = left
        self.right = right


def inorder(r: TreeNode) -> list[int]:
    return inorder(r.left) + [r.val] + inorder(r.right) if r else []


def inorder1(root : TreeNode, array : list):

    if root is None:
        return

    inorder1(root.left,array)

    array.append(root.val)

    inorder1(root.right,array)




root = TreeNode(2)

root.left = TreeNode(1)

root.left.right = TreeNode(3)

arr = []

inorder1(root,arr)

print(arr)

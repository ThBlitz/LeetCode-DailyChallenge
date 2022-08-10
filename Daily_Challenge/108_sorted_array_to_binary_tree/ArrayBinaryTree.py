

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def sortedArrayToBST(nums):
    
    def recur(left, right):
        if left > right:
            return None
        mid = (left + right) // 2
        return TreeNode(val = nums[mid], left = recur(left, mid - 1), right = recur(mid + 1, right))
    
    return recur(0, len(nums) - 1)


nums = [-2, -1, 0, 1, 2]
root = sortedArrayToBST(nums)

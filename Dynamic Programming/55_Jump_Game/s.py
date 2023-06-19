# You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

# Return true if you can reach the last index, or false otherwise.


# Example 1:

# Input: nums = [2,3,1,1,4]
# Output: true
# Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
# Example 2:

# Input: nums = [3,2,1,0,4]
# Output: false
# Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

class Solution:
    def canJump(self, nums: list[int]) -> bool:
        if len(nums) == 0:
            return True

        jump_to = [False for _ in range(len(nums))]

        jump_to[0] = True

        for i in range(1,len(nums)):
            for j in range(i - 1, 0,-1):
                if jump_to[j] > 0 and j + nums[j] >= i:
                    jump_to[i] = True
                    break


        return jump_to[-1]


nums = [2,3,1,1,4]

s = Solution()

print(s.canJump(nums))
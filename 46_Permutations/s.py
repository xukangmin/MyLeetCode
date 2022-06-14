


from threading import stack_size


class Solution:
    res = []

    def permute(self, nums: list) -> list:

        self.res = []
        track = []
        stack_level = 0
        self.backtrack(nums, track, stack_level)
        return self.res
    
    def backtrack(self, nums : list, track : list, stack_level : int):

        stack_level = stack_level + 1

        print('stack_level='+ str(stack_level))

        if len(track) == len(nums):
            self.res.append(track.copy())
            return

        for i in range(0, len(nums)):
            
            if nums[i] in track:
                continue


            print('index='+str(i))

            track.append(nums[i])

            self.backtrack(nums, track, stack_level)

            track.pop()


s = Solution()

result = s.permute([1,2,3])


print(result)


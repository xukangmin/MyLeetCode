triangle_input = [[2],[3,4],[6,5,7],[4,1,8,3]]

items = [5, 3, 2, 7]
size_of_pack = 11


class Solution:
    def backpack(self, items: list[int], size_of_pack: int) -> int:
        n = len(items)
        m = size_of_pack
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        for i in range(n):
            for j in range(m + 1):
                if items[i] > j:
                    dp[i + 1][j] = dp[i][j]
                else:
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - items[i]] + items[i])


        return dp[n][m]

s = Solution()

ret = s.backpack(items,size_of_pack)

print(ret)
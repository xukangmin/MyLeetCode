# Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

# The testcases will be generated such that the answer is unique.

# A substring is a contiguous sequence of characters within the string.


# Example 1:

# Input: s = "ADOBECODEBANC", t = "ABC"
# Output: "BANC"
# Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
# Example 2:

# Input: s = "a", t = "a"
# Output: "a"
# Explanation: The entire string s is the minimum window.
# Example 3:

# Input: s = "a", t = "aa"
# Output: ""
# Explanation: Both 'a's from t must be included in the window.
# Since the largest window of s only has one 'a', return empty string.

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = {}
        window = {}

        for c in t:
            need[c] = 1
            window[c] = 0

        left = 0
        right  = 0

        valid = 0

        start = 0
        total_len = len(s)

        while right < len(s):

            c = s[right]

            right += 1

            if c in need.keys():
                window[c] += 1

                if window[c] == need[c]:
                    valid += 1

            while valid == len(list(need.keys())):
                
                if right - left < total_len:
                    start = left
                    total_len = right - left

                d = s[left]

                left += 1

                if d in need.keys():
                    if window[d] == need[d]:
                        valid -= 1

                    window[d] -= 1
        
        return "" if total_len == len(s) else s[start:start + total_len]

sol = Solution()

s = "ADOBECODEBACMS"
t = "ABC"

r = sol.minWindow(s,t)


print(r)

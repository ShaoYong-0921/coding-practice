#
# @lc app=leetcode id=1071 lang=python3
#
# [1071] Greatest Common Divisor of Strings
#

# @lc code=start
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        #switch str1 to longest string
        if len(str1) < len(str2):
            str1, str2 = str2, str1
        
        if str1 == str2:
            return str1
        
        if str1[:len(str2)] != str2:
            return ""
        
        return self.gcdOfStrings(str1[len(str2):], str2)
        
        

# @lc code=end


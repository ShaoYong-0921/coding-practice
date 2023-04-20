#
# @lc app=leetcode id=383 lang=python3
#
# [383] Ransom Note
#

# @lc code=start
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        str_list = []
        for i in magazine:
            str_list.append(i)
        for j in ransomNote:
            if j not in str_list:
                return False
            str_list.pop(str_list.index(j))
        return True
        
# @lc code=end

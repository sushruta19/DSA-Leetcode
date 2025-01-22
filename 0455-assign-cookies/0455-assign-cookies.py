class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        j, content = 0, 0
        for i in range(len(s)):
            if s[i] >= g[j]:
                content+=1
                j += 1
                if j == len(g):
                    break
        return content

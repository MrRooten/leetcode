class Solution:
    def countAndSay(self, n: int):
        res = ""
        if n == 1:
            return "1"

        if n == 2:
            return "11"


        if n == 3:
            return "21"
        pre = self.countAndSay(n-1)
        i = 0
        j = 0
        count = 1
        while j+1 < len(pre):
            if pre[j] == pre[j+1]:
                count += 1
            else:
                res += str(count)+pre[j]
                count = 1
            j += 1
        
        res += str(count) + pre[j]
        return res

s = Solution()
for i in (1,31):
    print("")
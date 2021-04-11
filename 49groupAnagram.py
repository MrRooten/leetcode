class Solution:
    def groupAnagrams(self, strs):
        ans_map = {}
        set_list = list()
        for s in strs:
            tmp_list = list(s)
            tmp_list.sort()
            if tmp_list not in set_list:
                set_list.append(tmp_list)
            ans_map.setdefault(set_list.index(tmp_list),[])
            ans_map[set_list.index(tmp_list)].append(s)
        
        ans = []
        for k in ans_map.keys():
            ans.append(ans_map[k])

        return ans


s = Solution()
print(s.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
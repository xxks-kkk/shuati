# Given a string containing only digits, restore it by returning all possible valid IP address combinations.
#
# For example:
# Given "25525511135",
#
# return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def dfs(res, path, s):
            if len(path) == 4:
                if len(s) == 0:
                    res.append(".".join(path))
                return
            last_one_digit = s[-1:]
            last_two_digit = s[-2:]
            last_three_digit = s[-3:]
            if last_one_digit != '':
                dfs(res, [last_one_digit]+path, s[:-1])
            if last_two_digit != '' and len(last_two_digit) == 2 and last_two_digit[0] != '0':
                dfs(res, [last_two_digit]+path, s[:-2])
            if last_three_digit != '' and int(last_three_digit) <= 255 and len(last_three_digit) == 3 and last_three_digit[0] != '0':
                dfs(res, [s[-3:]]+path, s[:-3])
            return
        res = []
        dfs(res, [], s)
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.restoreIpAddresses("25525511135"))
    print(sol.restoreIpAddresses("0000"))
    print(sol.restoreIpAddresses("010010"))
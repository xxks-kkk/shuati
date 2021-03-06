class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x

class Solution:
    def royalNames(self, array):
        # Version 1
        def romanToInt(romanNumeral):
            dict = {
                "I": 1,
                "V": 5,
                "X": 10,
                "L": 50,
                "C": 100,
                "D": 500,
                "M": 1000
            }
            i, res = 0, 0
            while i < len(romanNumeral):
                s1 = dict[romanNumeral[i]]
                if i + 1 < len(romanNumeral):
                    s2 = dict[romanNumeral[i + 1]]
                    if s1 >= s2:
                        res += s1
                        i += 1
                    else:
                        res = res + s2 - s1
                        i = i + 2
                else:
                    res += s1
                    i += 1
            return res
        res = []
        dict = {}
        for royalname in array:
            name, romanNumeral = royalname.split(" ")
            if name in dict:
                dict[name].append((romanToInt(romanNumeral), romanNumeral))
            else:
                dict[name] = [(romanToInt(romanNumeral), romanNumeral)]
        for key in sorted(dict.keys()):
            res.extend([key + " " + str(i[-1]) for i in sorted(dict[key], reverse=True)])
        return res

    def royalNames1(self, array):
        # Version 2
        def romanToInt(romanNumeral):
            dict = {
                "I": 1,
                "V": 5,
                "X": 10,
                "L": 50,
                "C": 100,
                "D": 500,
                "M": 1000
            }
            i, res = 0, 0
            while i < len(romanNumeral):
                s1 = dict[romanNumeral[i]]
                if i + 1 < len(romanNumeral):
                    s2 = dict[romanNumeral[i + 1]]
                    if s1 >= s2:
                        res += s1
                        i += 1
                    else:
                        res = res + s2 - s1
                        i = i + 2
                else:
                    res += s1
                    i += 1
            return res
        res = []
        for royalname in array:
            name, romanNumeral = royalname.split(" ")
            res.append(name + str(romanToInt(romanNumeral)))
        # https://stackoverflow.com/questions/6422700/how-to-get-indices-of-a-sorted-array-in-python
        indices = sorted(range(len(res)),key=res.__getitem__)
        return [array[i] for i in indices]


if __name__ == "__main__":
    sol = Solution()
    array = ["Albert II","Polo IV","Alw V","Elizabeth XXV", "Albert XL","Polo XLVI"]
    print(sol.royalNames1(array))
    print(sol.royalNames(array))
    array2 = ["Philippe I", "Philip II"]
    print(sol.royalNames(array2))

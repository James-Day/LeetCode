class Solution:
    def makeGood(self, s: str) -> str:
        list = []
        for char in s:
            list.append(char)
            if len(list) >= 2:
                if abs(ord(list[-1]) - ord(list[-2])) == 32:
                    list.pop()
                    list.pop()
        return "".join(list)
                
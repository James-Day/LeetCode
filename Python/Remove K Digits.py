#in the future for checking emptiness, I will just say if stack instead of if len(stack) != 0
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for c in num:
            while k > 0 and len(stack) != 0 and stack[-1] > c:
                k-=1
                stack.pop()
            stack.append(c)
        stack = stack[0:len(stack) - k] #remove remaining k elements
        res = "".join(stack).lstrip('0') # remove leading zeros, I initially did this by converting to int, but the size of the number is beyond the limit, especially for other programming languages!
        return res if len(res) != 0 else "0"
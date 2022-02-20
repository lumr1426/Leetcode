class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack=[]
        for i in s:
            if len(stack)==0:
                stack.append(i)
                continue
            top=stack[-1]
            stack.append(i)
            if top==stack[-1]:
                stack.pop()
                stack.pop()
            
        return "".join(stack)

class Solution:
    def maxDepth(self, s: str) -> int:
        stack=list()
        stackcount=list()
        count=0
        maxval=0
        
        for i in s:
            if i=='(':
                stack.append('(')
                count+=1
                if maxval<count:
                    maxval=count
            elif i==')':
                stack.pop()
                count-=1
                if len(stack)==0:
                    stackcount.append(maxval)
                    count=0
                    maxval=0
            else:
                continue
                
        if len(stackcount)==0:
            return 0
        
        return max(stackcount)
                    
            

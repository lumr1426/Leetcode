class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack=list()
        s=list(s)
        eraseind=list()
        startind=0
        endind=0

        # 지워야할 인덱스 찾는 과정
        for i in range(len(s)):
            if s[i]=='(':
                if len(stack)==0:
                    startind=i    
                stack.append('(')
            else:
                    stack.pop()
                    if(len(stack)==0):
                        endind=i
                        eraseind.append(startind)
                        eraseind.append(endind)
                        
        # 지워야할 인덱스 지워주기     
        for i in range(len(eraseind)):
            del s[eraseind[i]-i]
            
        return "".join(s)       

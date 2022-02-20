class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        queue=list()
        for i in range(n):
            queue.append(i)
        cur=0
        while len(queue)>1:
            cur=(k-1+cur)%len(queue)
            del queue[cur]
        return queue[0]+1

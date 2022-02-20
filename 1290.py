# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        integer=[]
        ans=0
        while head:
            integer.append(head.val)
            head=head.next
        length=len(integer)
        integer.reverse()
        for i in range(length):
            ans+=(2**i)*integer[i]
        return ans
            
        
        

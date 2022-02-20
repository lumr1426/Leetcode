# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head=ListNode()
        start=head
        sum=0
        while l1 or l2:
            sum//=10
            if l1:
                sum+=l1.val
                l1=l1.next
            if l2:
                sum+=l2.val
                l2=l2.next
            head.next=ListNode(sum%10)
            head=head.next
        if sum//10==1:
            head.next=ListNode(1)
        return start.next

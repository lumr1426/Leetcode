# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur=ans=head
        if head==None: return head
        while cur.next:
            cur=cur.next
            if head.val==cur.val: continue
            else:
                head.next=cur
                head=head.next
        head.next=None
        return ans

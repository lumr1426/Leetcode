# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy=ListNode()
        if head==None: return head
        dummy.next=head
        ans=dummy
        while dummy!=None and dummy.next!=None:
            if dummy.next.val==val:
                temp=dummy
                while temp.next!=None and temp.next.val==val:
                    temp=temp.next
                dummy.next=temp.next
            dummy=dummy.next
        return ans.next

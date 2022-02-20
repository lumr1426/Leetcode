# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        cur1=headA
        cur2=headB
        cnt1=cnt2=0
        while cur1:
            cnt1+=1;
            cur1=cur1.next
        while cur2:
            cnt2+=1;
            cur2=cur2.next
        if cnt1>=cnt2:
            for i in range(cnt1-cnt2):
                headA=headA.next
        else:
            for i in range(cnt2-cnt1):
                headB=headB.next
        while headA:
            if headA==headB: return headA
            headA=headA.next
            headB=headB.next
        return None

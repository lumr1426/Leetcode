/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1, *cur2;
        cur1=headA;
        cur2=headB;
        int cnt1=0;
        int cnt2=0;
        while(cur1!=NULL)
        {
            cnt1++;
            cur1=cur1->next;
        }
        while(cur2!=NULL)
        {
            cnt2++;
            cur2=cur2->next;
        }
        if(cnt1>=cnt2)
        {
            for(int i=0;i<cnt1-cnt2;i++) headA=headA->next;
        }
        else
        {
            for(int i=0;i<cnt2-cnt1;i++) headB=headB->next;
        }
        while(headA!=NULL)
        {
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};

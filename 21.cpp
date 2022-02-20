/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=new ListNode();
        ListNode *answer;
        
        if(list1==NULL&&list2==NULL) return NULL;
        
        if(list1==NULL||list2==NULL) return list1==NULL?list2:list1;
        
        if(list1->val<=list2->val)
        {
            head->val=list1->val;
            list1=list1->next;
            head->next=new ListNode();
            answer=head->next;
        }
        else
        {
            head->val=list2->val;
            list2=list2->next;
            head->next=new ListNode();
            answer=head->next;
        }
        while(list1!=NULL||list2!=NULL)
        {
            if(list1==NULL)
            {
                answer->val=list2->val;
                if(list2->next==NULL) break;
                answer->next=new ListNode();
                list2=list2->next;
                answer=answer->next;
                continue;
            }
            if(list2==NULL)
            {
                answer->val=list1->val;
                if(list1->next==NULL) break;
                answer->next=new ListNode();
                list1=list1->next;
                answer=answer->next;
                continue;
            }
            if(list1->val<=list2->val)
            {
                answer->val=list1->val;
                answer->next=new ListNode();
                list1=list1->next;
                answer=answer->next;
            }
            else
            {
                answer->val=list2->val;
                answer->next=new ListNode();
                list2=list2->next;
                answer=answer->next;
            }
        }
        return head;
    }
};

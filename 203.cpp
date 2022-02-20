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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode *ans=dummy;
        if(head==NULL) return NULL;
        while(dummy!=NULL&&dummy->next!=NULL)
        {
            if(dummy->next->val==val)
            {
                ListNode *temp=dummy;
                while(temp->next!=NULL&&temp->next->val==val)
                {
                    temp=temp->next;
                }
                dummy->next=temp->next;
            }
            dummy=dummy->next;
        }
        return ans->next;
    }
};

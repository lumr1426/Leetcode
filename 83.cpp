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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur=head;
        ListNode *ans=head;
        if(head==NULL) return NULL;
        while(cur->next!=NULL)
        {
            cur=cur->next;
            if(cur->val==head->val) continue;
            else
            {
                head->next=cur;
                head=head->next;
            }
        }
        head->next=NULL;
        return ans;
    }
};

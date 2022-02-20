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
    ListNode* middleNode(ListNode* head) {
        int nodecount=0;
        ListNode* firsthead=head;
        while(head!=NULL)
        {
            head=head->next;
            nodecount++;
        }
        for(int i=0;i<nodecount/2;i++)
        {
            firsthead=firsthead->next;
        }
        return firsthead;
    }
};

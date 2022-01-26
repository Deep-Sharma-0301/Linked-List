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
    ListNode*reverse(ListNode *head)
{
//reverse from middle to end 
    ListNode*pre=NULL;
    
    while(head!=NULL)
    {
        ListNode*next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}


bool isPalindrome(ListNode* head) {
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
	    //finding the middle element
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow->next=reverse(slow->next);
    slow=slow->next;
    
    while(slow!=NULL)
    {
        if(head->val!=slow->val)
        {
            return false;
        }
        head=head->next;
        slow=slow->next;
    }
    return true;
}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode *head) {
        int ans = 0;
        
        while (head) {
            ++ans;
            head = head->next;
        }
        
        return ans;
    }
    
    ListNode *advance(ListNode *head, int by) {
        for (int cnt = 1; cnt <= by; ++cnt) {
            head = head->next;
        }
        
        return head;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        
        int lenA = length(headA), lenB = length(headB);
        
        if (lenA > lenB) {
            headA = advance(headA, lenA - lenB);
        } else if (lenB > lenA) {
            headB = advance(headB, lenB - lenA);
        }
        
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
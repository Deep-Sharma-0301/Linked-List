class Solution {
public:
    ListNode* findMiddle(ListNode *head) {
        ListNode *slow = head;
		// we have to start this fast pointer from head's next to avoid some edge case (one case when there are only 2 nodes in this case we will get wrong answer if we start fast pointer from head instead of head's next)
        ListNode *fast = head->next;               
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode *a, ListNode *b) {
        if(!a && !b) return NULL;
        if(!a) return b;
        if(!b) return a;

        ListNode *head = NULL;
        if(a->val <= b->val) {
            head = a;
            head->next = merge(a->next, b);
        }
        else {
            head = b;
            head->next = merge(a, b->next);
        }
        return head;
    }

    ListNode* mergeSort(ListNode* head) {
        if(head==NULL || head->next==NULL) {
            return head;
        }

        ListNode *middle = findMiddle(head);
        ListNode *tNode = middle->next;
        middle->next = NULL;

        ListNode *a = mergeSort(head);
        ListNode *b = mergeSort(tNode);

        head = merge(a, b);
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
#define node ListNode
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
	ListNode* hasCycle(ListNode *head) {
		node* s = head, *f = head;

		while (f and f->next) {
			f = f->next->next;
			s = s->next;

			if (f == s) return f;
		}
		return NULL;
	}
	ListNode *detectCycle(ListNode *head) {
		ListNode* ans = hasCycle(head);
		if (ans == NULL) return NULL;

		ListNode* f = ans;
		ListNode* s = head;

		while (f->next != s->next) {
			f = f->next;
			s = s->next;
		}
		f->next=NULL;

	}
};

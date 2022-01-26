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
    bool hasCycle(ListNode *head) {
        ListNode * current=head;
        map<ListNode *,bool>visit;
        while(current!=NULL){ 
            // check if the node was visited, if visited then we detected a cycle
            if(visit.find(current)!=visit.end())return true;
            else
            visit[current]=true; // visit node
            // update the current node
            current=current->next;
        }
        return false;
    }
};
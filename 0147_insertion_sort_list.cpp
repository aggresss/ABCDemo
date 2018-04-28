/**
* Algorithm of Insertion Sort:
*     1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
*     2. At each iteration, insertion sort removes one element from the input data, 
*         finds the location it belongs within the sorted list, and inserts it there.
*     3. It repeats until no input elements remain.
*/

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
    ListNode* insertionSortList(ListNode* head) {  
        ListNode preHead(0), * p, * next;
        while(head != NULL) {  
            next = head->next;  
            p = &preHead;
            while(p->next != NULL && p->next->val <= head->val) {  
                p = p->next;  
            }
            head->next = p->next;
            p->next = head;
            head = next;
        }  
        return preHead.next;  
    }
};

/**
* You are given two non-empty linked lists representing two non-negative integers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            return l1 == NULL ? l2 : l1;
        }
        int value = l1->val + l2->val;
        ListNode* result = new ListNode(value % 10);
        result->next = addTwoNumbers(l1->next, l2->next);
        if (value >= 10) {
            result->next = addTwoNumbers(new ListNode(value / 10), result->next);
        }
        return result;
    }
};

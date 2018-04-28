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
 
class Solution1 {
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

class Solution2 {
public:
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
};
 
class Solution3 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* head = new ListNode(-1);
    	ListNode* p = head;
    	ListNode* p1 = l1;
    	ListNode* p2 = l2;
    	int c = 0, val1, val2, sum;
        while(p1 || p2 || c != 0){
        	val1 = p1 == NULL ? 0 : p1->val;
        	val2 = p2 == NULL ? 0 : p2->val;
        	sum = val1 + val2 + c;
        	c = sum/10;
        	ListNode* node = new ListNode(sum%10);
        	p->next = node;
        	p = node;
        	p1 = p1 != NULL ? p1->next : NULL;
        	p2 = p2 != NULL ? p2->next : NULL;
        }
        return head->next;
    }
};

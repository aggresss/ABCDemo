/**
* Given a linked list, remove the n-th node from the end of list and return its head.
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode preHead(0), *p = &preHead;
        p->next = head;
        for(int i = 0; i < n; i++){
            head = head->next;
        }
        while(head != NULL){
            head = head->next;
            p = p->next;
        }
        p->next = p->next->next;
        return preHead.next;
    }
};

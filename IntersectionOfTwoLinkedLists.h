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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *n1=headA, *n2 = headB;
        
        if(!n1 || !n2) return NULL;
        
		/*
		if intersection exists listA = A + intersection and listB = B + intersection 
		we can concatenate both lists: listA+listB = A + intersection + B + intersection = listB+listA
		therefore: 
		(1) loop both pointers n1 and n2 through their list, if n1 == n2 -> result found
		(2) if end of their list is reached link to other list 
		(3) find intersecting node
		*/
        while(n1 && n2 && n1!=n2) {
            n1 = n1->next;
            n2 = n2->next;
            
            if(n1 == n2) return n1;
            
            if(!n1) n1 = headB;
            if(!n2) n2 = headA;
        }
        
        return n1;
    }
};
//https://leetcode.com/problems/intersection-of-two-linked-lists/

/* solution using stacks (above is faster and needs less memory

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        
        while(headA) s1.push(headA), headA = headA->next;
        while(headB) s2.push(headB), headB = headB->next;
        
        if(s1.top() != s2.top()) return NULL;
        
        ListNode* intersection = NULL;
        while(!s1.empty() && !s2.empty() && s1.top() == s2.top()) 
            intersection = s1.top(), s1.pop(), s2.pop();
        
        return intersection;
    }
};

*/
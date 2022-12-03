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
private:
    //divide the list into two lists, first one has n nodes, second one the rest
    ListNode* split(ListNode* head, int n) {
        for(int i=1; head && i<n; i++) head = head->next;
        
        if(!head) return NULL;
        
        ListNode* split_off_head = head->next;
        head->next = NULL;
        return split_off_head;
    }
    
    //merge two lists l1 and l2; append the merged lists to the head; return the tail of the merged sorted list
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        
        cur->next = (l1 ? l1 : l2);
        while(cur->next) 
            cur = cur->next;
        
        return cur;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *cur = head, *left, *right, *tail;
        //find length of list
        int length = 0;
        while(cur) {
            length++;
            cur = cur->next;
        }
        
        ListNode dummy (0);
        dummy.next = head;
        //iterate through all nodes using merge sort to sort the list
        for(int i=1; i<length; i <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            
            while(cur) {
                left = cur;
                right = split(left, i);
                cur = split(right, i);
                tail = merge(left, right, tail);
            }
        }
        
        return dummy.next;
    }
};
//https://leetcode.com/problems/sort-list/
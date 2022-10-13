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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode *tail = head;
        //find tail and count nodes
        int count = 1;
        while(tail->next) {
            tail = tail->next;
            count++;
        }
        
        //circle linked list than move the tail k times 
        //if the number of rotations is not a multiple of the elements in the list
        tail->next = head;
        if(k %= count) 
            for(int i=0; i<count-k; i++)
                tail = tail->next;
        
        //break circle
        head = tail->next;
        tail->next = NULL;
        
        return head;
    }
};
//https://leetcode.com/problems/rotate-list/
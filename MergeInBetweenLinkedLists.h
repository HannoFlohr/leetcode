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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        b -= a-1; 

        //increment to start point of insert
        while(--a) {
            list1 = list1->next;
        }
        ListNode* start_insert = list1;
        
        //increment to end point of insert
        while(b--) {
            list1 = list1->next;
        }cout<<list1->val<<endl;

        //insert list2 at start point
        start_insert->next = list2;
        //increment list2 to the end and insert rest of list1 at that end
        while(list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = list1->next;

        return head;
    }
};
//https://leetcode.com/problems/merge-in-between-linked-lists/
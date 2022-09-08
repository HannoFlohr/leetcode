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
    
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
        
    if(list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        
        int n = lists.size();
        short interval = 1;
        
        while(interval < n) {
            for(int i=0; i < n-interval; i += 2*interval)    
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            
            interval *= 2;
        }
        
        return lists[0];
    }
};
//https://leetcode.com/problems/merge-k-sorted-lists/
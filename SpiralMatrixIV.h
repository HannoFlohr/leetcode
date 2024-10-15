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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        const vector<vector<int>> directions {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> spiral (m, vector<int>(n, -1));
        int curDirection = 0, i = 0, j = -1;
        vector<int> stepsToTake {n, m-1};
        
        while(head != nullptr && stepsToTake[curDirection % 2]) {
            for(int k = 0; k < stepsToTake[curDirection%2]; ++k) {
                i += directions[curDirection][0];
                j += directions[curDirection][1];
                spiral[i][j] = head->val;
                
                head = head->next;
                if(head == nullptr) 
                    break;
            }
            
            stepsToTake[curDirection%2]--;
            curDirection = (curDirection+1) % 4;
        }
        
        return spiral;
    }
};
//https://leetcode.com/problems/spiral-matrix-iv/
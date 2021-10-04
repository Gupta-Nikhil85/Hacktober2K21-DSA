// Question URL:- https://leetcode.com/problems/linked-list-cycle/
// Github:- Gupta-Nikhil85

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode Node;
class Solution {
public:
    bool hasCycle(ListNode *head) {
    	//storing the node every time in an unordered map
        unordered_map<Node*, int> m;
        Node* temp= head;
        while(temp){
            temp=temp->next;
            // if node found in map, then return 1
            if(m[temp]>0){
                return 1;
            }
                m[temp]++;
        }
        //else return 0
        return 0;
    }
};

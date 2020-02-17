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
    void deleteNode(ListNode* node) {
        if(node == NULL)
            return;
        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;
        delete delNode;
        return;
    }
};

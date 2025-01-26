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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = head;
        ListNode* firstNode = head; 
        ListNode* secondNode = head; 
        int i = 0; 
        while (i < n && secondNode->next != nullptr) {
            secondNode = secondNode->next;
            ++i;
        }
        if (i < n && firstNode != secondNode) {
            result = firstNode->next;
            delete firstNode; 
            return result; 
        }
        else if (i < n && firstNode == secondNode) {
            delete firstNode; 
            return nullptr;
        }

        while (firstNode != secondNode && secondNode->next != nullptr) {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }

        if (firstNode->next == nullptr) {
            delete firstNode;
            return nullptr;
        }
        ListNode* victim = firstNode->next; 
        firstNode->next = firstNode->next->next;
        delete victim;

        return result; 
    }
};
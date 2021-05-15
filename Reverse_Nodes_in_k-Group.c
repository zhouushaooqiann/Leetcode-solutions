/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(k == 1) return head;

    // an empty list
    if(head == NULL) return NULL;
    
    struct ListNode* curNode = head;
    struct ListNode* tailNode = head;
    
    // move current node by k position to check if it has k nodes
    for(int i = 0; i < k; i++){
        // there're less than k nodes left
        if(tailNode == NULL) return head; 
        tailNode = tailNode -> next;
    }

    if(k == 2){
        struct ListNode* nextNode = curNode -> next;
        nextNode -> next = curNode;
        curNode -> next = reverseKGroup(tailNode, k);
        return nextNode;
    } else {
        struct ListNode* nextNode = curNode -> next;
        struct ListNode* lastNode = nextNode -> next;
        curNode -> next = reverseKGroup(tailNode, k);
        while(lastNode != tailNode){
            nextNode -> next = curNode;
            curNode = nextNode;
            nextNode = lastNode;
            lastNode = lastNode -> next;
        }
        nextNode -> next = curNode;
        return nextNode;
    }
}

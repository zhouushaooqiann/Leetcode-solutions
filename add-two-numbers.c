/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    // initialize the entry node of linklist sum (this pointer is preserved)
    struct ListNode* sum = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node_sum = sum;

    struct ListNode* node1 = l1;
    struct ListNode* node2 = l2;
    int accu = 0;
    node_sum->val = (node1->val + node2->val) % 10;
    node_sum->next = NULL;
    accu = (node1->val + node2->val)/10;
     
    // both l1 and l2 haven't ended
    while(node1->next && node2->next){
        // create a new node and move to it
        node_sum->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        node_sum = node_sum->next;
        node1 = node1 -> next;
        node2 = node2 -> next;

        // calculate the sum
        node_sum->val = (node1->val + node2->val + accu) % 10;
        node_sum->next = NULL;
        accu = (node1->val + node2->val + accu)/10;
    }

    // 11 hasn't ended, l2 ended already
    while(node1->next){
        node_sum->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        node_sum = node_sum->next;
        node1 = node1 -> next;

        node_sum->val = (node1->val + accu) % 10;
        node_sum->next = NULL;
        accu = (node1->val + accu)/10;
    }

    // 12 hasn't ended, l1 ended already
    while(node2->next){
        node_sum->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        node_sum = node_sum->next;
        node2 = node2 -> next;

        node_sum->val = (node2->val + accu) % 10;
        node_sum->next = NULL;
        accu = (node2->val + accu)/10;
    }

    if(accu == 1){
        node_sum->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        node_sum = node_sum->next;

        node_sum->val = 1;
        node_sum->next = NULL;
    }

    return sum;
}

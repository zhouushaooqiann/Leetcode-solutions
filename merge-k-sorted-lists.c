/**
 * Author: Shaoqian Zhou
 * Date: Mar. 31th 2021
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *merge2Lists(int i1, int i2, struct ListNode** lists);
struct ListNode *doMerge(struct ListNode* list1, struct ListNode* lists2);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    // set the head of origin
    if(listsSize == 0) return NULL;
    return merge2Lists(0, listsSize - 1, lists);
}

struct ListNode *merge2Lists(int i1, int i2, struct ListNode** lists){
    // base case
    if(i1 == i2) return lists[i1];
    else if(i1 + 1 == i2) return doMerge(lists[i1], lists[i2]);

    // recursive case
    else return doMerge(merge2Lists(i1, (i1 + i2 - 1)/2, lists), merge2Lists((i1 + i2 - 1)/2 + 1, i2, lists));
}

struct ListNode *doMerge(struct ListNode* list1, struct ListNode* lists2){
    struct ListNode *head = list1;
    // get the head of next wait-for-merge list
    struct ListNode *merge = lists2;
    struct ListNode *origin = head;
    // the broken node under previous merge
    struct ListNode *broken;

    // check if need to reset head
    if(merge != NULL && origin != NULL && merge->val < origin->val) head = merge;
    else if(merge != NULL && origin == NULL) head = merge;
    
    // keep moving until one of the two linklists ends
    while(merge != NULL && origin != NULL){
        // last injected node is in the end
        if(merge->val < origin->val){
            while(merge->next != NULL){
                if(merge->next->val >= origin->val) break;
                else merge = merge->next;
            }

            // either reach the end or is equal or bigger
            // preserve the old next
            broken = merge->next;
            merge->next = origin;
            // move the head
            merge = broken;
        }
        // newly injected node is greater than or equal to the node in origin linklist
        else{
            while(origin->next != NULL){
                if(origin->next->val > merge->val) break;
                else origin = origin->next;
            }

            // either reach the end of origin or is bigger than head
            broken = origin->next;
            origin->next = merge;
            // move origin
            origin = broken;
        }
    }
    return head;
}

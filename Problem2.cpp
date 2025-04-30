// Time Complexity : O(m*n)
// Space Complexity : O(1)  
// Did this code successfully run on Leetcode : Yes


// Your code here along with comments explaining your approach:
// 1. Create a answer linked list with head as null.
// 2. Merge every linked lisd with answer linked.
// 3. Return head of answer linked list.

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
    ListNode* MergeSort(ListNode* head,ListNode* x){
        ListNode* t=head;
        ListNode* pr=NULL;
        ListNode* tb=x;
        while(t!=NULL && tb!=NULL){
            if((t->val) <= (tb->val)){
                pr=t;
                t=t->next;
            }
            else{
                if(pr!=NULL){
                    pr->next = tb;
                    ListNode* temp=tb;
                    tb=tb->next;
                    temp->next=t;
                    pr=temp;
                }
                else{
                    head=tb;
                    tb=tb->next;
                    head->next=t;
                    t=head;
                }
            }
        }
        if(tb!=NULL){
            if(pr==NULL){
                head=tb;
            }
            else{
                pr->next=tb;
            }
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        int n=lists.size();
        ListNode* head=lists[0];
        for(int i=1;i<n;i++){
            head = MergeSort(head,lists[i]);
            //return head;
        }
        return head;
    }
};
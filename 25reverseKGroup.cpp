#include "ListNode.cpp"
ListNode* helper(ListNode* head,int k) {
    if (k == 0 || k == 1) {
        return head;
    }
    int n = 0;
    ListNode* node = head;
    while(node) {
        node = node->next;
        n++;
    }

    if (k > n || n == 1 || n == 0) {
        return head;
    }


    vector<ListNode*> nodes(k+1);
    node = head;
    for(int i=0;i <= k;i++) {
        nodes[i] = node;
        if (node == NULL) {
        } else {
            node =  node->next;
        }
    }
    nodes[k] = helper(nodes[k],k);

    for(int i=k-1;i > 0;i--) {
        nodes[i]->next = nodes[i-1];
    }

    nodes[0]->next = nodes[k];
    return nodes[k-1];
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return helper(head,k);
    }
};

int main(int argc,char** argv) {
    vector<int> args = {1,2,3,4,5,6,7};
    ListNode* head = linklistFromVector(args);
    Solution s;
    head = s.reverseKGroup(head,3);
    printLinklist(head);
    deleteLinklist(head);
}
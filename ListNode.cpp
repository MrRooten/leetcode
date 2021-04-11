#include <vector>
#include <cstdio>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* linklistFromVector(vector<int> v) {
    ListNode dummy;
    ListNode* node = &dummy;
    for(int i=0;i < v.size();i++) {
        node->next = new ListNode(v[i]);
        node = node->next;
    }

    return dummy.next;
}

void printLinklist(ListNode* head) {
    ListNode* node = head;
    while(node) {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("\n");
}

void deleteLinklist(ListNode* head) {
    ListNode* node = head;
    while(node) {
        ListNode* last = node;
        node = node->next;
        delete last;
    }
}
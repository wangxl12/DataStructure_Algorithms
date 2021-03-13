#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        if (head->next->next == nullptr) {
            ListNode *temp = head->next;
            head->next = nullptr;
            temp->next = head;
            return temp;
        } else {
            ListNode *p;
            ListNode *q;
            p = head;
            q = head->next->next;
            head = head->next;
            p->next = nullptr;
            while (q != nullptr) {
                head->next = p;
                p = head;
                head = q;
                q = q->next;
            }
            head->next = p;
            return head;
        }
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode();
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head = s.reverseList(head);
    while(head!=nullptr){
        cout << (head->val);
        head = head->next;
    }
    return 0;
}

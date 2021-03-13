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
        if(head == nullptr || head->next == nullptr){
            return head;  // 要注意这里返回不能为空
        }
        ListNode *tail = head->next;  // 回溯前 tail 一直往后移动
        ListNode *p = reverseList(head->next); // 返回的p的指向一直没有改变 一直指向翻转后的头结点
        head->next = tail->next; // 先将翻转前的结点指向空
        tail->next = head; // 然后翻转
        return p;
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

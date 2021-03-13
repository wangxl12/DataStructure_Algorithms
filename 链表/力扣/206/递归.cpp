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
            return head;  // Ҫע�����ﷵ�ز���Ϊ��
        }
        ListNode *tail = head->next;  // ����ǰ tail һֱ�����ƶ�
        ListNode *p = reverseList(head->next); // ���ص�p��ָ��һֱû�иı� һֱָ��ת���ͷ���
        head->next = tail->next; // �Ƚ���תǰ�Ľ��ָ���
        tail->next = head; // Ȼ��ת
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

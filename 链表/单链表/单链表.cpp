#include<iostream>
using namespace std;

//class Node;
class Node{
public:
	int value;
	Node* next=NULL;
	Node(int v=0){
		value = v;
	}
	int getValue(){
		return value;
	}
	int setValue(int v){
		value = v;
	}
};

class Link{
private:
	int length = 10;
	Node* head = NULL;
public:
	Link(int len){
		length = len;
		Link::createLink(length);
	}
	void createLink(int len){
		Node* p;
		head = new Node(3);
		p = head;
		for(int i=1;i<len;i++){
			p->next = new Node(i);
			p = p->next;
		}
	}
	void insert(int index,int v){
		Node* p = head;
		Node* temp = new Node(v);
		if(index==0){
			temp->next = head;
			head = temp;
			length++;
		}
		else{
			index=index<=length? index:length;  // 防止越界 
			for(int i=0;i<index-1;i++){
				p = p->next;
			}
			temp->next = p->next;
			p->next = temp;
			length++;
		}
	}
	int getLength(){
		return length;
	}
	void del(int index){
		if(length<1){
			cout << "链表为空！"; 
			return ;
		}
		else if(index>length-1){
			cout << "访问链表越界！";
			return ; 
		}
		if(index==0){
			Node* D = head;
			head = head->next;
			delete D;
			length--;
		}
		else{
			Node* p = head;
			Node* D;
			for(int i=0;i<index-1;i++){
				p = p->next;
			}
			if(p->next == NULL){
				p->next;
			}
			D = p->next;  // 释放动态分配的内存，防止内存泄漏 
			p->next = p->next->next;
			delete D;
		}
		length--;
	}
	void display(){
		if(head==NULL){
			cout << "创建链表失败!";
			return ;
		}
		for(Node* p=head;p!=NULL;p=p->next){
			cout << p->value<<',';
		}
		cout << endl;
	}
};

int main(){
	Link link(10);
//	cout << link.getLength();
	link.display();
	link.insert(20, 999);
	link.display();
	link.del(0);
	link.display();
	link.del(7);
	link.display();
	return 0;
}

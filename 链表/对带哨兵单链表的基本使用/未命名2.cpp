#include<iostream>
#define ElemType int
using namespace std;

class Node{
private:
	ElemType val=0;
	Node* next=nullptr;
public:
	Node(ElemType val) {this->val = val;}
	Node(ElemType val, Node* next){this->val = val;this->next = next;}
	ElemType getVal() {return this->val;}
	Node* getNext() {return this->next;}
	void setNext(Node* next) {this->next = next;}
	void setVal(ElemType val) {this->val = val;}
};

class LinkedList{
private:
	int len;
	Node* head=nullptr;
public:
	int getLength(){return len;}
	Node* getHead(){return head->getNext();}
	Node* del(int n){
		
	}
	Node* insert(int n, ElemType val){
		if(n<=0){
			cout << "please input the correct insert place!" << endl;
			return nullptr;
		}
		if(n>len){
			Node* p;
			for(p = getHead();p->getNext()!=nullptr;p=p->getNext());
			Node* node = new Node(val);
			p->setNext(node);
		} 
		else{
			Node* p = getHead();
			for(int i=1;i<n;i++){
				p = p->getNext();
			}
			Node* node = new Node(val);
			node->setNext(p->getNext());
			p->setNext(node);
		}
		len++;
	}
	LinkedList(Node* h){
		head = h;
		len = 0;
	}
	void display(){
		for(Node* p = getHead();p!=nullptr;p=p->getNext()){
			cout << p->getVal() << ' ';
		}
	}
};
int main(){
	Node* node = new Node(0);
	LinkedList l1(node);
	for(int i=1;i<=10;i++){
		l1.insert(i, i*i);
	}
	l1.display();
//	cout << l1.getHead();
	return 0;
} 

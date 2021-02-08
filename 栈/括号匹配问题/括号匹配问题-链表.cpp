#include<stdlib.h>
#include<stdio.h> 
#include<iostream>
#include<string>
using namespace std;

typedef char ElemType;
ElemType LEFTARRAY[] = {'(','[','{'};
ElemType RIGHTARRAY[] = {')',']','}'};

typedef struct Node{
	ElemType val;
	struct Node* next;
}LinkStackNode;

typedef struct Stack{
	int length;
	struct Node* top;
}LinkStack;

LinkStack* createStack(){
	// ��������ֱ��stack=NULL������û��Ϊstack�����ڴ�ռ䣬�������top����. 
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->length = 0;  // ע������ĳ�ʼ��ֵ�����ڽṹ������У���Ч 
	stack->top = nullptr;
	return stack;
}	
void push(LinkStack* stack, ElemType val){
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	node->val = val;
	node->next = nullptr; 
	if(stack->top == nullptr){
		stack->top = node;
	}
	else{
		node->next = stack->top;
		stack->top = node;
	}
	stack->length++;
}
ElemType pop(LinkStack* stack){
	if(stack->length<=0){
		cout << "ջΪ��!"; 
		return '\0';
	}
	ElemType val = stack->top->val;
	LinkStackNode* node = stack->top;
	free(node);
	stack->top = stack->top->next;
	stack->length--;
	return val;
}
bool bracketMatch(string& str){
	LinkStack* stack = createStack();
	for(string::iterator it=str.begin();it!=str.end();it++){
		if(*it == LEFTARRAY[0]||*it == LEFTARRAY[1]||*it == LEFTARRAY[2]){
			push(stack, *it);
		}
		else if(*it == RIGHTARRAY[0]){

			if(LEFTARRAY[0] != pop(stack)){
				cout << "'" << LEFTARRAY[0] << "'" << "��" 
				<< "'" << *it << "'" << "��ƥ��" << endl;
				return 0;
			}
		}
		else if(*it==RIGHTARRAY[1]){
		
			if(LEFTARRAY[1] != pop(stack)){
				cout << "'" << LEFTARRAY[1] << "'" << "��" 
				<< "'" << *it << "'" << "��ƥ��" << endl;
				return 0;
			}
		}
		else if(*it==RIGHTARRAY[2]){
		
			if(LEFTARRAY[2] != pop(stack)){
				cout << "'" << LEFTARRAY[2] << "'" << "��" 
				<< "'" << *it << "'" << "��ƥ��" << endl;
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	cout << "������ʽ��" << endl;
	string str;
	cin >> str;
	if(bracketMatch(str)) cout << "ƥ����ȷ";
	else cout << "ƥ�����";
	return 0;
}

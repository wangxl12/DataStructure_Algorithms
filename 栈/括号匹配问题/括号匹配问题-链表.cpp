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
	// 这里容易直接stack=NULL，这样没有为stack分配内存空间，后面访问top报错. 
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->length = 0;  // 注意这里的初始赋值不能在结构体里进行，无效 
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
		cout << "栈为空!"; 
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
				cout << "'" << LEFTARRAY[0] << "'" << "与" 
				<< "'" << *it << "'" << "不匹配" << endl;
				return 0;
			}
		}
		else if(*it==RIGHTARRAY[1]){
		
			if(LEFTARRAY[1] != pop(stack)){
				cout << "'" << LEFTARRAY[1] << "'" << "与" 
				<< "'" << *it << "'" << "不匹配" << endl;
				return 0;
			}
		}
		else if(*it==RIGHTARRAY[2]){
		
			if(LEFTARRAY[2] != pop(stack)){
				cout << "'" << LEFTARRAY[2] << "'" << "与" 
				<< "'" << *it << "'" << "不匹配" << endl;
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	cout << "输入表达式：" << endl;
	string str;
	cin >> str;
	if(bracketMatch(str)) cout << "匹配正确";
	else cout << "匹配错误";
	return 0;
}

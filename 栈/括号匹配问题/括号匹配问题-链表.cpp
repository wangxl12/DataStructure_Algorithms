#include<stdlib.h>
#include<iostream>
#include<string>
#define ElemType char
using namespace std;


using namespace std;
typedef struct Node{
	ElemType val;
	struct Node* next;
}LinkStackNode;

typedef struct Stack{
	int length=0;
	struct Node* top;
}LinkStack;

LinkStack* createStack(){
	LinkStack* stack;
	return stack;
}
void push(LinkStack* stack, ElemType val){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->val = val;
	node->next = stack->top;
	stack->top = node;
	stack->length++;
}
ElemType pop(LinkStack* stack){
	if(stack->length<=0){
		cout << "栈为空!"; 
		return '\0';
	}
	ElemType val = stack->top->val;
	struct Node* node = stack->top;
	free(node);
	stack->top = stack->top->next;
	stack->length--;
	return val;
}
bool bracketMatch(string& str){
	LinkStack* stack = createStack();
	for(string::iterator it=str.begin();it!=str.end();it++){
		if(*it == '('||*it == '['||*it == '{'){
			push(stack, *it);
		}
		else if(*it == ')'||*it==']'||*it=='}'){
			if(*it != pop(stack)) return 0;
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

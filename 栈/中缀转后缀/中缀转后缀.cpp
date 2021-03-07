#include<iostream>
#include<string>
#include<vector>
using namespace std;

void infixToPostfix(string& str){
	vector<char> op;  // 存放运算符 
	int spatial=0;
	for(int i=0;i<str.length();i++){
		if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z')){  
		// 直接输出数字 
			cout << str[i];
		}
		else if(str[i]=='('){  // 将左括号存入栈 
			op.push_back(str[i]);
			spatial = 1;
		}
		else if(str[i]==')'){
			while(op.back()!='('){  // 将所有内容弹出直至遇到右括号 
				cout << op.back();
				op.pop_back();
			}
			op.pop_back(); // 左括号 
			spatial = 0;
		}
		else{  // 如果是操作符 
			if(str[i]=='*'||str[i]=='/'||str[i]=='-'){
				// 减乘除需要入栈，因为后面可能是一个括号 
				op.push_back(str[i]);
			} 
			else {
				// 乘除优先级比+高，需要弹出，-与+优先级相同 
				while(!op.empty()){
					if(op.back()=='(') break;
					cout << op.back();
					op.pop_back();
				}
				op.push_back(str[i]);
			}
		}
	}
	while(!op.empty()){
		cout << op.back();
		op.pop_back();
	}
}

int main(){
	string str;
	cout << "input a infix expression:" << endl;
	cin >> str;
	infixToPostfix(str);
	return 0;
}

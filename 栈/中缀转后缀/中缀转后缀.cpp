#include<iostream>
#include<string>
#include<vector>
using namespace std;

void infixToPostfix(string& str){
	vector<char> op;  // �������� 
	int spatial=0;
	for(int i=0;i<str.length();i++){
		if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z')){  
		// ֱ��������� 
			cout << str[i];
		}
		else if(str[i]=='('){  // �������Ŵ���ջ 
			op.push_back(str[i]);
			spatial = 1;
		}
		else if(str[i]==')'){
			while(op.back()!='('){  // ���������ݵ���ֱ������������ 
				cout << op.back();
				op.pop_back();
			}
			op.pop_back(); // ������ 
			spatial = 0;
		}
		else{  // ����ǲ����� 
			if(str[i]=='*'||str[i]=='/'||str[i]=='-'){
				// ���˳���Ҫ��ջ����Ϊ���������һ������ 
				op.push_back(str[i]);
			} 
			else {
				// �˳����ȼ���+�ߣ���Ҫ������-��+���ȼ���ͬ 
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

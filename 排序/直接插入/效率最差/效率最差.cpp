#include<iostream>
using namespace std;

void DirectInsertSort(int array[],int n){
	for(int i=1;i<n;i++){  // �ӵڶ���Ԫ�ؿ�ʼ�������� 
		for(int j=i-1;j>=0;j--){ // ��ǰ�������Ԫ�رȽϴ�С 
			if(array[i]>=array[j]){  // ������ڵ�ǰָ���Ԫ�أ����뵱ǰԪ�صĺ�һ��λ�� 
				int keep = array[i];
				for(int temp=i-1;temp>j;temp--){  // �������Ԫ��ȫ������ 
					array[temp+1] = array[temp];
				} 
				array[j+1] = keep;  // ������Ԫ�� 
				break;
			}
			if(j==0){  // ����Ƚϵ������һ����û�в��� 
				int keep = array[i];
				for(int temp=i-1;temp>=0;temp--){
					array[temp+1] = array[temp];
				}
				array[0] = keep;  // ���뵽����ĵ�һ��λ�� 
			}
		}
	}
	
} 
int main(){
	int N = 10;
	int array[N] = {3, 4, 8, 2, 3, 0, 7, 9, 3, 3};
	DirectInsertSort(array, 10);
	for(int i= 0;i<N;i++){
		cout << array[i];
	}
	return 0;
} 

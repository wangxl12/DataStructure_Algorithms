#include<iostream>
using namespace std;

void sort(int array[], int n){
	for(int i=1;i<n;i++){
		int temp = array[i];
		int j = i-1;
		for(;array[j]>temp;j--){  // ���ڱ������ڱ�������
		// ���ڱ���Ҫ�ж�j��0�Ĵ�С������Ҫ��֤0����Ҳ�ƶ�
			if(j<0) break; 
			array[j+1] = array[j];
		}
		// �ж�j���С��0��˵��ȫ������temp�����ڵ���0˵���Ѿ��ҵ�������λ��
		if(j>=0) array[j+1] = temp;
		// j<0�������������û���룬 
		else  array[0] = temp; 
	}
}

int main(){
	int N = 10;
	int array[N] = {4, 3, 6, 8, 4, 5, 1, 2, 9, 6};
	sort(array, N);
	for(int i=0;i<N;i++){
		cout << array[i];
	}
	cout << endl;
	return 0;
} 

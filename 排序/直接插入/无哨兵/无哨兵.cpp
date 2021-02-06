#include<iostream>
using namespace std;

void sort(int array[], int n){
	for(int i=1;i<n;i++){
		int temp = array[i];
		int j = i-1;
		for(;array[j]>temp;j--){  // 无哨兵和有哨兵的区别
		// 无哨兵需要判断j和0的大小，而且要保证0索引也移动
			if(j<0) break; 
			array[j+1] = array[j];
		}
		// 判断j如果小于0，说明全部大于temp，大于等于0说明已经找到待插入位置
		if(j>=0) array[j+1] = temp;
		// j<0有两种情况，还没插入， 
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

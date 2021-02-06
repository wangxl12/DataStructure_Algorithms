#include<iostream>
using namespace std;

void DirectInsertSort(int array[],int n){
	for(int i=1;i<n;i++){  // 从第二个元素开始决定插入 
		for(int j=i-1;j>=0;j--){ // 跟前面的所有元素比较大小 
			if(array[i]>=array[j]){  // 如果大于当前指向的元素，插入当前元素的后一个位置 
				int keep = array[i];
				for(int temp=i-1;temp>j;temp--){  // 将后面的元素全部后移 
					array[temp+1] = array[temp];
				} 
				array[j+1] = keep;  // 插入新元素 
				break;
			}
			if(j==0){  // 如果比较到了最后一个都没有插入 
				int keep = array[i];
				for(int temp=i-1;temp>=0;temp--){
					array[temp+1] = array[temp];
				}
				array[0] = keep;  // 插入到数组的第一个位置 
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

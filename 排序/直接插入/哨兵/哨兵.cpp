#include<iostream>
using namespace std;

void sort(int array[], int N){
	for(int i=2;i<N;i++){
		array[0] = array[i];
		int j;
		for(j = i-1;array[0]<array[j]&&j>0;j--){
			array[j+1] = array[j];
		}
		array[j+1] = array[0];
	}
} 
int main(){
	int N = 11;
	int array[N] = {0, 3, 5, 2, 6, 8, 4, 2, 9, 3, 1};
	sort(array, N);
	for(int i=1;i<N;i++){
		cout << array[i];
	}
	return 0;
}

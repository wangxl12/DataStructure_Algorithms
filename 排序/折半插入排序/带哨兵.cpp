#include <iostream>
#define Elem int
using namespace std;

void Binary_Insertion_Sort(int* a, int N){
    int j = 1;
    int left = 1, right = 2;  // !!! right = 2 instead of right = 1
    int mid = 1;
    for(int n = 2;n <= N;n++){  // !!! n<=N instead of n<N
        a[0] = a[n];  // put the insert value to soldier
        left = 1, right = n-1;
        // find the insertion index
        while(left < right){  // left < right instead of left <= right
            mid = (left + right) / 2;
            if(a[0] > a[mid]) left = mid+1;  // !!! a[0] > a[mid] instead of a[i]>a[mid]
            else if(a[0] <= a[mid]) right = mid;  // !!! a[0] <= a[mid] instead of a[i]<=a[mid]
        }
        for(j = n;j>=left+1;j--){  // move and insert
            a[j] = a[j - 1];
        }
        a[j] = a[0];
    }
    // cout
    for(int k = 1;k<N;k++){
        cout << a[k];
    }
}
int main() {
    int N = 8;
    Elem a[] = {0, 3, 5, 7, 2, 9, 3, 0};  // set the first elem as soldier
    Binary_Insertion_Sort(a, N);
}


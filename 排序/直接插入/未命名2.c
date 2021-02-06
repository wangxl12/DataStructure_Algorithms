#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a, b;
    int result;
    int array[7];
    scanf("%d %d", &a, &b);
    result = a + b;
    if(abs(result) < 10000){
        printf("%d",  result);
    }
    else{
        int i = 0;
        int symbol;
        if(result >= 0){
            symbol = 1;
        }
        else{
            symbol = -1;
            result = abs(result);
        }
        for(;i < 7 && result != 0;i++){
            array[i] = result % 10;
            result /= 10;
        }
        array[i - 1] *= symbol;
    	
		int temp = i - 1;
    	for (;temp>=0;temp--){
    		printf("%d",array[temp]);
		}
		printf("\n");
        
		short int cnt = 0;
        int j = i - 1;
        for(;j >= 0;j--){
            cnt ++;
            if(cnt == 4){
                printf(",");
                cnt = 0;
                j++;
            }
            else{
                printf("%d", array[j]);
            }
        }
    }
    return 0;
}

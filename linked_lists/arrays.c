#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("YOOOO");
    int numbers[] ={12,8,3,10};
    int sum = 0;

    for(int i =0; i<=5; i++){
        sum += numbers[i];
    }

    for(int i =0; i<=5; i++){
        numbers[i] /= sum;
    }

    for(int i =0; i<=5; i++){
        printf("%d",numbers[i]);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func(int a,int b,int c){
    int d = b*b - (4*a*c);
    return d;
}

int main()
{
    int a,b,c;
    printf("Enter a, b and c \n");

    scanf("%d %d %d",&a,&b,&c);

    int discriminant = func(a,b,c);
    if (a!=0){
        if(discriminant>0){
        float X1,X2;
        X1 = (-b + sqrt(discriminant))/2*a;
        X2 = (-b - sqrt(discriminant))/2*a;

        printf("X1 = %.2f \n X2 = %.2f",X1,X2);

        }
        else if(discriminant==0){
            float x =(-b)/2*a;
            printf("The root is %f",x);
        }
        else{
            printf("Roots are complex");
        }

    }
    else {
            printf("Enter a number for a");
            scanf("%d",&a);
    }




    return 0;
}

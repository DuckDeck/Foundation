
#include <stdio.h>

int main(){
    short num;
    num = 1;
    // printf("this is a simple");
    // printf("computer.\n");
    // printf("%lu \n",sizeof(num));
    // printf("My favorite number is %d because it is first .\n",num);



     int a = 3;
    printf("a: %p \n",&a);
    int *b;
    b = &a;
    printf("b: %p \n",b);
    printf("b: address %p \n",&b);
    printf("value b: %d",*b);
    return 1;

   
}


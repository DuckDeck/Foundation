#include <stdio.h>

int main(){
    printf("hello world\n");
    return 0;
}

//use gcc 生成可执行文件 
//gcc test.c
// ./a.out
//print hello world


//使用gcc 预编译
// gcc test.c > test.i //生成了预编译文件test.i
//使用gcc编译
//gcc -S test.i -o test.s //生成了编译好的文件test.i
//或者使用命令把预编译和编译一起执行
//gcc -S test.c -o test.s
//汇编,将编译好的文件变成机器码
//as test.s -o test.o 或者 gcc -c test.s -o test.o
//或者直接将源码编译成目标文件
//gcc -c test.c -o test.o

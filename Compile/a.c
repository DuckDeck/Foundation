#include <stdio.h>
extern int shared;
void swap(int* a,int* b);
int main(){
    int a = 100;
    swap(&a,&shared);
}

//使用命令ld a.o b.o -e main -o ab 
//来链接两个文件后成ab.o
//-e main 表示将main函数作为程序入口，ld链接器默认的程序入口为_start
//-o ab表示链接的输出文件为ab.o
//这个时侯会出错：
/* 
Undefined symbols for architecture x86_64:
  "main", referenced from:
     implicit entry/start for main executable
     (maybe you meant: _main)
ld: symbol(s) not found for inferred architecture x86_64
*/
//换成命令  ld a.o b.o -e _main -o ab  出会两个警告
//ld: warning: No version-min specified on command line
//ld: dynamic main executables must link with libSystem.dylib for inferred architecture x86_64
//加上最小版本命令 -macosx_version_min 10.14  
//ld -macosx_version_min 10.14 a.o b.o -e _main -o ab  后第一个警告没了，但是还少一个动态库
//要加上libSystem.dylib动态库，因为我们是在系统上编程，所以要用系统的接口，需要系统库
//ld -macosx_version_min 10.14 a.o b.o -e _main -o ab -lSystem
//这样就可以成功输出ab.o文件了


//我们来dump一下
//objdump -h a.o
/*
a.o:     file format mach-o-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         00000027  0000000000000000  0000000000000000  000001d8  2**4
                  CONTENTS, ALLOC, LOAD, RELOC, CODE
  1 __LD.__compact_unwind 00000020  0000000000000028  0000000000000028  00000200  2**3
                  CONTENTS, RELOC, DEBUGGING
  2 .eh_frame     00000040  0000000000000048  0000000000000048  00000220  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 */

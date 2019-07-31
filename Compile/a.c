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
//可以看出这里和书本上很多不一样

// objdump -h b.o
/*
b.o:     file format mach-o-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         0000002c  0000000000000000  0000000000000000  00000228  2**4
                  CONTENTS, ALLOC, LOAD, CODE
  1 .data         00000004  000000000000002c  000000000000002c  00000254  2**2
                  CONTENTS, ALLOC, LOAD, DATA
  2 __LD.__compact_unwind 00000020  0000000000000030  0000000000000030  00000258  2**3
                  CONTENTS, RELOC, DEBUGGING
  3 .eh_frame     00000040  0000000000000050  0000000000000050  00000278  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 */

//再来dump 生成的ab  objdump -h ab
/*
ab:     file format mach-o-x86-64

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .text         0000005c  0000000000001f70  0000000000001f70  00000f70  2**4
                  CONTENTS, ALLOC, LOAD, CODE
  1 .eh_frame     00000030  0000000000001fd0  0000000000001fd0  00000fd0  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .data         00000004  0000000000002000  0000000000002000  00001000  2**2
                  CONTENTS, ALLOC, LOAD, DATA
 */

int printf(const char* format, ... );
int global_init_var = 84;
int global_uninit_var;

void func1(int i){
    printf("%d\n",i);
}

int main(void){
    static int static_var = 85;
    static int static_var2;
    int a = 1;
    int b;
    func1(static_var + static_var2 + a + b);
    return a;
}
//gcc -c section.c
//objdump -h section.o 打出段里的信息,和书里的不一样，可能是架构不一样的原因

/*
section.o:      file format Mach-O 64-bit x86-64

Sections:
Idx Name          Size（16进制） Address（16进制）  Type
  0 __text        00000068 0000000000000000 TEXT 
  1 __data        00000008 0000000000000068 DATA 
  2 __cstring     00000004 0000000000000070 DATA 
  3 __bss         00000004 0000000000000120 BSS
  4 __compact_unwind 00000040 0000000000000078 DATA 
  5 __eh_frame    00000068 00000000000000b8 DATA 
   */

  //size section.o size用来查看section里的各种个段的长度,这是10进制的
  /*
  __TEXT  __DATA  __OBJC  others  dec     hex
212     12      0       64      288     120 */

//查看段的详细信息  objdump -s -d section.o
/*
section.o:      file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
_func1:
       0:       55      pushq   %rbp
       1:       48 89 e5        movq    %rsp, %rbp
       4:       48 83 ec 10     subq    $16, %rsp
       8:       89 7d fc        movl    %edi, -4(%rbp)
       b:       8b 75 fc        movl    -4(%rbp), %esi
       e:       48 8d 3d 5b 00 00 00    leaq    91(%rip), %rdi
      15:       b0 00   movb    $0, %al
      17:       e8 00 00 00 00  callq   0 <_func1+0x1c>
      1c:       89 45 f8        movl    %eax, -8(%rbp)
      1f:       48 83 c4 10     addq    $16, %rsp
      23:       5d      popq    %rbp
      24:       c3      retq
      25:       66 2e 0f 1f 84 00 00 00 00 00   nopw    %cs:(%rax,%rax)
      2f:       90      nop

_main:
      30:       55      pushq   %rbp
      31:       48 89 e5        movq    %rsp, %rbp
      34:       48 83 ec 10     subq    $16, %rsp
      38:       c7 45 fc 00 00 00 00    movl    $0, -4(%rbp)
      3f:       c7 45 f8 01 00 00 00    movl    $1, -8(%rbp)
      46:       8b 05 00 00 00 00       movl    (%rip), %eax
      4c:       03 05 00 00 00 00       addl    (%rip), %eax
      52:       03 45 f8        addl    -8(%rbp), %eax
      55:       03 45 f4        addl    -12(%rbp), %eax
      58:       89 c7   movl    %eax, %edi
      5a:       e8 00 00 00 00  callq   0 <_main+0x2f>
      5f:       8b 45 f8        movl    -8(%rbp), %eax
      62:       48 83 c4 10     addq    $16, %rsp
      66:       5d      popq    %rbp
      67:       c3      retq
Contents of section __text:
 0000 554889e5 4883ec10 897dfc8b 75fc488d  UH..H....}..u.H.
 0010 3d5b0000 00b000e8 00000000 8945f848  =[...........E.H
 0020 83c4105d c3662e0f 1f840000 00000090  ...].f..........
 0030 554889e5 4883ec10 c745fc00 000000c7  UH..H....E......
 0040 45f80100 00008b05 00000000 03050000  E...............
 0050 00000345 f80345f4 89c7e800 0000008b  ...E..E.........
 0060 45f84883 c4105dc3                    E.H...].
Contents of section __data:
 0068 54000000 55000000                    T...U...
Contents of section __cstring:
 0070 25640a00                             %d..
Contents of section __bss:
<skipping contents of bss section at [0120, 0124)>
Contents of section __compact_unwind:
 0078 00000000 00000000 25000000 00000001  ........%.......
 0088 00000000 00000000 00000000 00000000  ................
 0098 30000000 00000000 38000000 00000001  0.......8.......
 00a8 00000000 00000000 00000000 00000000  ................
Contents of section __eh_frame:
 00b8 14000000 00000000 017a5200 01781001  .........zR..x..
 00c8 100c0708 90010000 24000000 1c000000  ........$.......
 00d8 28ffffff ffffffff 25000000 00000000  (.......%.......
 00e8 00410e10 8602430d 06000000 00000000  .A....C.........
 00f8 24000000 44000000 30ffffff ffffffff  $...D...0.......
 0108 38000000 00000000 00410e10 8602430d  8........A....C.
 0118 06000000 00000000                    ........
 */
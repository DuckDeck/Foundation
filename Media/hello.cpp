#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "media.h"

int yuv420_split(char* url,int w,int h,int num);
int main() {
    int a;
    yuv420_split("Media/material/yuv420.yuv",256,256,1);
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "media.h"
using namespace std;
int yuv420_split(char* url,int w,int h,int num);

int main() {

    yuv420_split("Media/material/yuv420.yuv",256,256,1);
    getchar();
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "media.h"
using namespace std;
int yuv420_split(char* url,int w,int h,int num);
int yuv444_split(char *url, int w, int h, int num);
int yuv420_gray(char *url, int w, int h, int num);
int main() {

    //yuv420_split("Media/material/yuv420.yuv",256,256,1);
    //yuv444_split("Media/material/yuv444p.yuv",256,256,1);
    yuv420_gray("Media/material/yuv420.yuv",256,256,1);
    getchar();
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "media.h"
using namespace std;
int yuv420_split(char* url,int w,int h,int num);
int yuv444_split(char *url, int w, int h, int num);
int yuv420_gray(char *url, int w, int h, int num);
int yuv420_harf_luminance(char *url, int w, int h, int num);
int yuv420_add_Border(char *url, int w, int h, int border, int num);
int yuv420_graybar(int width, int height, int ymin, int ymax, int barnum, char *url_output);
int main() {

    //yuv420_split("Media/material/yuv420.yuv",256,256,1);
    //yuv444_split("Media/material/yuv444p.yuv",256,256,1);
    //yuv420_gray("Media/material/yuv420.yuv",256,256,1);
    //yuv420_harf_luminance("Media/material/yuv420.yuv",256,256,1);
    //yuv420_add_Border("Media/material/yuv420.yuv",256,256,20,1);
    yuv420_graybar(500, 200, 0, 255, 32, "Media/material/yuv420_graybar.yuv");
    getchar();
    return 0;
}

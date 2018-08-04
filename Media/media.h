#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#ifndef CIRCLE_H
#define CIRCLE_H
//本程序中的函数可以将YUV420P数据中的Y、U、V三个分量分离开来并保存成三个文件
//如果视频帧的宽和高分别为w和h，那么一帧YUV420P像素数据一共占用w*h*3/2 Byte的数据。其中前w*h Byte存储Y，
//接着的w*h*1/4 Byte存储U，最后w*h*1/4 Byte存储V。上述调用函数的代码运行后，将会把一张分辨率为256x256的名称为lena_256x256_yuv420p.
//yuv的YUV420P格式的像素数据文件分离成为三个文件
//output_420_y.y：纯Y数据，分辨率为256x256。
//output_420_u.y：纯U数据，分辨率为128x128。
//output_420_v.y：纯V数据，分辨率为128x128。

int yuv420_split(char* url,int w,int h,int num){
    FILE *fp = fopen(url,"rb+");
    FILE *fp1 = fopen("Media/material/output_420_y.y","wb+");
    FILE *fp2 = fopen("Media/material/output_420_u.y","wb+");
    FILE *fp3 = fopen("Media/material/output_420_v.y","wb+");
    unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);
    for(int i=0;i<num;i++){
        fread(pic,1,w*h*3/2,fp);
        fwrite(pic,1,w*h,fp1);
        fwrite(pic + w * h,1,w*h/4,fp2);
        fwrite(pic+w*h*5/4,1,w*h/4,fp3);
    }
    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
//(2)分离YUV444P像素数据中的Y、U、V分量
//从代码可以看出，如果视频帧的宽和高分别为w和h，那么一帧YUV444P像素数据一共占用w*h*3 Byte的数据。其中前w*h Byte存储Y，
//接着的w*h Byte存储U，最后w*h Byte存储V。上述调用函数的代码运行后，将会把一张分辨率为256x256的名称为lena_256x256_yuv444p.
//yuv的YUV444P格式的像素数据文件分离成为三个文件：
int yuv444_split(char *url,int w,int h,int num){
    FILE *fp = fopen(url,"rb+");
    FILE *fp1 = fopen("Media/material/output_444_y.y","wb+");
    FILE *fp2 = fopen("Media/material/output_444_u.y","wb+");
    FILE *fp3 = fopen("Media/material/output_444_v.y","wb+");
    unsigned char *pic = (unsigned char *)malloc(w * h * 3);
    for(int i=0;i<num;i++){
        fread(pic,1,w*h*3,fp);
        fwrite(pic,1,w*h,fp1);
        fwrite(pic + w * h,1,w*h,fp2);
        fwrite(pic+w*h*2,1,w*h,fp3);
    }
    free(pic);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}

//(3) 将YUV420P像素数据去掉颜色（变成灰度图）
//如果想把YUV格式像素数据变成灰度图像，只需要将U、V分量设置成128即可。这是因为U、V是图像中的经过偏置处理的色度分量。色度分量在偏置处理前的取值范围是-128至127，
//这时候的无色对应的是“0”值。经过偏置后色度分量取值变成了0至255，因而此时的无色对应的就是128了。上述调用函数的代码运行后，
//将会把一张分辨率为256x256的名称为lena_256x256_yuv420p.yuv的YUV420P格式的像素数据文件处理成名称为output_gray.yuv的YUV420P格式的像素数据文件
int yuv420_gray(char *url,int w,int h,int num){
    FILE *fp = fopen(url, "rb+");
    FILE *fp1 = fopen("Media/material/output_yuv420_gray.yuv", "wb+");
    unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);
    for (int i = 0; i < num; i++){
        fread(pic, 1, w * h * 3 / 2, fp);
        memset(pic + w * h, 128, w * h / 2);
        fwrite(pic, 1, w * h * 3 / 2, fp1);
    }
    free(pic);
    fclose(fp);
    fclose(fp1);
    return 0;
}
#endif
//(4)将YUV420P像素数据的亮度减半
//如果打算将图像的亮度减半，只要将图像的每个像素的Y值取出来分别进行除以2的工作就可以了。图像的每个Y值占用1 Byte，取值范围是0至255，
//对应C语言中的unsigned char数据类型。上述调用函数的代码运行后，将会把一张分辨率为256x256的名称为lena_256x256_yuv420p.yuv的YUV420P格式的像素数据文件处理成名称为output_half.yuv的YUV420P格式的像素数据文件
int yuv420_harf_luminance(char *url,int w,int h,int num){
    FILE *fp = fopen(url, "rb+");
    FILE *fp1 = fopen("Media/material/output_yuv420_harf_luminance.yuv", "wb+");
    unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);
    for (int i = 0; i < num; i++){
        fread(pic, 1, w * h * 3 / 2, fp);
        for (int j = 0; j < w * h; j++)
        {
            unsigned char temp = pic[j] / 2;
            pic[j] = temp;
        }
        fwrite(pic, 1, w * h * 3 / 2, fp1);
    }
    free(pic);
    fclose(fp);
    fclose(fp1);
    return 0;
}
//(5)将YUV420P像素数据的周围加上边框
//图像的边框的宽度为border，本程序将距离图像边缘border范围内的像素的亮度分量Y的取值设置成了亮度最大值255。上述调用函数的代码运行后，
//将会把一张分辨率为256x256的名称为lena_256x256_yuv420p.yuv的YUV420P格式的像素数据文件处理成名称为output_border.yuv的YUV420P格式
//的像素数据文件
int yuv420_add_Border(char *url,int w,int h,int border,int num){
    FILE *fp = fopen(url, "rb+");
    FILE *fp1 = fopen("Media/material/output_yuv420_add_border.yuv", "wb+");
    unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);
    for (int i = 0; i < num;i++){
        fread(pic, 1, w * h * 3 / 2, fp);
        for (int j = 0; j < h;j++){
            for (int k = 0; k < w;k++){
                if(k < border || k > (w-border) || j < border || j > (h - border)){
                    pic[j * w + k] = 255; //只能用0或者255。不能用其他的数，，因为这不是RGB
                }
            }
        }
        fwrite(pic, 1, w * h * 3 / 2, fp1);
    }
    free(pic);
    fclose(fp);
    fclose(fp1);
    return 0;
}

//(6) 生成YUV420P格式的灰阶测试图

int yuv420_graybar(int width, int height, int ymin,int ymax,int barnum,char *url_output)
{
    int barwidth;
    float lum_inc;
    unsigned char lum_temp;
    int uv_width, uv_height;
    FILE *fp = NULL;
    unsigned char *data_y=NULL;
	unsigned char *data_u=NULL;
	unsigned char *data_v=NULL;
    int t = 0, i = 0, j = 0;

    barwidth = width / barnum;
    lum_inc = (float)(ymax - ymin) / (float)(barnum - 1);
    uv_width = width / 2;
    uv_height = height / 2;

    data_y = (unsigned char *)malloc(width * height);
    data_u = (unsigned char *)malloc(uv_width * uv_height);
    data_v = (unsigned char *)malloc(uv_width * uv_height);
    if((fp = fopen(url_output,"wb+")) == NULL){
        printf("Error: Cannot create file!");
        return -1;
    }
    printf("Y, U, V value from picture's left to right:\n");
    for (t = 0; t < width / barwidth; t++)
    {
        lum_temp = ymin + (char)(t * lum_inc);
        printf("%3d,128,128\n", lum_temp);
    }
    for(j=0;j<height;j++){
		for(i=0;i<width;i++){
			t=i/barwidth;
            lum_temp = ymin + (char)(t * lum_inc);
            data_y[j * width + i] = lum_temp;
        }
	}
    for(j=0;j<uv_height;j++){
		for(i=0;i<uv_width;i++){
            data_u[j * uv_width + i] = 128;
        }
	}
    for (j = 0; j < uv_height;j++){
        for (i = 0; i < uv_width;i++){
            data_v[j * uv_width + i] = 128;
        }
    }
    fwrite(data_y, width * height, 1, fp);
    fwrite(data_u, uv_width * uv_height, 1, fp);
    fwrite(data_v, uv_width * uv_height, 1, fp);
    fclose(fp);
    free(data_y);
    free(data_u);
    free(data_v);
    return 0;
}
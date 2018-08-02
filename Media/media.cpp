#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

//本程序中的函数可以将YUV420P数据中的Y、U、V三个分量分离开来并保存成三个文件
//如果视频帧的宽和高分别为w和h，那么一帧YUV420P像素数据一共占用w*h*3/2 Byte的数据。其中前w*h Byte存储Y，
//接着的w*h*1/4 Byte存储U，最后w*h*1/4 Byte存储V。上述调用函数的代码运行后，将会把一张分辨率为256x256的名称为lena_256x256_yuv420p.
//yuv的YUV420P格式的像素数据文件分离成为三个文件
//output_420_y.y：纯Y数据，分辨率为256x256。
//output_420_u.y：纯U数据，分辨率为128x128。
//output_420_v.y：纯V数据，分辨率为128x128。

int yuv420_split(char* url,int w,int h,int num){
    FILE *fp = fopen(url,"rb+");
    FILE *fp1 = fopen("output_420_y.y","wb+");
    FILE *fp2 = fopen("output_420_u.y","wb+");
    FILE *fp3 = fopen("output_420_v.y","wb+");
    unsigned char *pic = (unsigned char *)malloc(w * h * 3 / 2);
    for(int i=0;i<num;i++){
        fread(pic,1,w*h*3/2,fp);
        fwrite(pic,1,w*h,fp1);
        fwrite(pic + w * h,1,w*h/4,fp2);
        fwrite(pic+w*h*5/4,1,w*h/4,fp3);
    }
    free(pic);
    free(fp);
    free(fp1);
    free(fp2);
    free(fp3);
    return 0;
}

int yuv444_split(char *url,int w,int h,int num){
    FILE *fp = fopen(url,"rb+");
    FILE *fp1 = fopen("material/output_444_y.y","wb+");
    FILE *fp2 = fopen("material/output_444_u.y","wb+");
    FILE *fp3 = fopen("material/output_444_v.y","wb+");
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
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


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
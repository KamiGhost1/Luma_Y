#include "head.h"


int main(int C, char **V){
    FILE *image;
    COLOR **RGB;
    float **Y;
    BMPFILEHEADER fh;
    BMPINFOHEADER ih;

    testParam(C, V);

    image = IOpen(V[2]);
    fh = readFH(image);
    ih = readIH(image);

    RGB = createColor(ih.bi_Height, ih.bi_Width);
    #ifdef debug
    printf("all okey\n");
    #endif

    fseek(image, fh.bfOffBits, SEEK_SET);
    IRead(image, RGB, ih.bi_Height, ih.bi_Width);
    fseek(image, fh.bfOffBits, SEEK_SET);
    #ifdef debug
    printf("all okey\n");
    #endif

    Y = crtLuma(ih.bi_Height, ih.bi_Width);
    chgLuma(RGB, Y, ih.bi_Height, ih.bi_Width);

    #ifdef debug
    printf("all okey\n");
    #endif

    IWrite(image, RGB, ih.bi_Height, ih.bi_Width);
    #ifdef debug
    printf("all okey\n");
    #endif

    fclose(image);
    free(RGB);
    printf("image change!\n");
    return 0;
}
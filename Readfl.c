#include <stdio.h>
#include <stdlib.h>

struct paket{
    int i;
    char m[256];
    float f;
};

int main(int argc, char *argv[])
{
    long size;
    struct paket p;
    FILE *pFile;
    pFile= fopen(argv[1], "rb");

    /*The file name is not set*/
    if (argc == 1){
        printf("Enter the file name");
    }

    /*Open the file*/
    else{

        while (fread(&p, sizeof(struct paket), 1, pFile)) {
            printf("%d %s %f\n", p.i, p.m, p.f);
        }

        puts("\n");

        /*File size*/
        fseek(pFile, 0, SEK_END);
        size = ftell(pFile);
        fseek(pFile, 0, SEK_SET);
        printf("File size: %ld%s", size, "\tbytes");

        fclose(pFile);

    }

    return 0;
}

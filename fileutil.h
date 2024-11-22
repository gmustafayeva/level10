#ifndef FILEUTIL_H
#define FILEUTIL_H

#define COLS 256 

char ** loadFileAA(char *filename, int *size);
char (*loadFile2D(char *filename, int *size))[COLS];
char * substringSearchAA(char *target, char **arr, int size);
char * substringSearch2D(char *target, char (*arr)[COLS], int size);
void freeAA(char **arr, int size);
void free2D(char (*arr)[COLS]);

#endif

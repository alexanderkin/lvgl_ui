#include <stdio.h>
#include <string.h>
#include "./StringTools.h"

int removeDotFromNumString(const char* src, char* dsc) {
    int pos = 0;
    int length = (int)strlen(src);
    for (int i = 0, j = 0; i < length; i++) {
        if (src[i] == '.') {
            pos = length - i - 1;
            continue;
        }
        dsc[j] = src[i];
        j++;
    }
    return pos;
}
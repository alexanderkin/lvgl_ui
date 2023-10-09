#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./StringTools.h"
#include "../generic/enum.h"

uint64_t getValueFromLineEditString(const char* src) {
    char temp[256] = { 0 };
    boolean_t after_dot = FALSE;
    uint8_t length = (uint8_t)strlen(src);
    uint8_t temp_length = 0, decimal_count = 0;
    for (uint8_t i = 0; i < length; i++) {
        if (src[i] == '.' && after_dot == FALSE) {
            after_dot = TRUE;
            continue;
        }
        if (after_dot == TRUE) {
            decimal_count++;
        }
        temp[temp_length] = src[i];
        if (decimal_count == 3) {
            return atoll(temp);
        }
        temp_length++;
    }
    if (after_dot == FALSE) {
        sprintf(temp, "%s000", temp);
        return atoll(temp);
    }
    for (uint8_t i = 0; i < 3 - decimal_count; i++) {
        sprintf(temp, "%s0", temp);
    }
    return atoll(temp);
}
#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

#include "../generic/struct.h"

//移除数字字符串中的'.'，并返回保留3位小数的整数
uint64_t getValueFromLineEditString(const char* src);

#endif // STRINGTOOLS_H
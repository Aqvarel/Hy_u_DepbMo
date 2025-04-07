#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define widthBin 32
#define widthOct 11
#define widthHex 8

unsigned long to_twos_complement(long num) {
    if (num >= 0) return (unsigned long)num;
    return (unsigned long)(~(-num) + 1);
}

void initialize(struct AppContext* context) {
    context->fromBase = DEFAULT_VALUE;
    context->toBase = DEFAULT_VALUE;
}

void doValid(struct AppContext* context) {
    int flag = good;
    int i = 0, j = 0;
    if(context->input[i] == '-' || context->input[i] == '+'){
        i++;
        j = 1;
    }
    int len = strlen(context->input);
    for(;context->input[i] != '\0' || flag == 1; i++){
        if(context->input[i] < '0' || context->input[i] >= '0'+context->fromBase){
            flag = error_first;
        }
    }
    int max_len = (context->fromBase == 2) ? 32 : (context->fromBase == 8) ? 11 : 10;
    if(len - j > max_len){
        flag = error_second;
    }
    context->flag = flag;
}

long convert_to_decimal(const char* str, int from_base) {
    if (from_base == 10) {
        return strtol(str, NULL, 10);
    }
    uint32_t raw = (uint32_t)strtoul(str, NULL, from_base);

    int32_t signed_value = (int32_t)raw;

    return (long)signed_value;
}

void unsigned_to_base(unsigned long num, int to_base, int width, char *result) {
    char buffer[33] = {0};
    int index = 0;
    const char *digits = "0123456789ABCDEF";

    if (num == 0) {
        buffer[index++] = '0';
    } else {
        while (num > 0) {
            buffer[index++] = digits[num % to_base];
            num /= to_base;
        }
    }

    if (width <= 0) {
        if (to_base == 2)
            width = widthBin;
        else if (to_base == 8)
            width = widthOct;
        else if (to_base == 16)
            width = widthHex;
    }

    int len = index;
    int pad = (width > len) ? width - len : 0;
    int i = 0;
    for (i = 0; i < pad; i++) {
        result[i] = '0';
    }
    for (int j = 0; j < len; j++, i++) {
        result[i] = buffer[len - 1 - j];
    }
    result[i] = '\0';
}

void convert_from_decimal(long num, int to_base, char *result) {
    if (to_base == 10) {
        sprintf(result, "%ld", num);
        return;
    }

    unsigned long unsigned_num = to_twos_complement(num);

    int width = 0;
    if (to_base == 2)
        width = widthBin;
    else if (to_base == 8)
        width = widthOct;
    else if (to_base == 16)
        width = widthHex;

    unsigned_to_base(unsigned_num, to_base, width, result);
}

void doConvert(struct AppContext* context) {
    doValid(context);
    if (context->flag == good) {
        long dec_value = convert_to_decimal(context->input, context->fromBase);
        convert_from_decimal(dec_value, context->toBase, context->answer);
    }
}


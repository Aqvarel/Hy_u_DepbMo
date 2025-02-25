#include "logic.h"
#include <stdlib.h>
#include <string.h>

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

int fromBase_to_ten(struct AppContext* context){
    int flag = good;
    doValid(context);
    if(context->flag == good){
        int output = 0;
        int i = 0;
        int isNegative = 0;
        if(context->input[i] == '-'){
            i++;
            isNegative = 1;
        }
        while(context->input[i] != '\0'){
            output = (output * context->fromBase) + (context->input[i] - '0');
            i++;
        }
        return isNegative ? -output : output;
    }

    return context->flag = error_first;
}

void fromTen_to_ToBase(struct AppContext* context) {
    int newInput = fromBase_to_ten(context);
    if(newInput < 0){
        newInput = -newInput;
        itoa(newInput,context->answer,context->toBase);
        int len = strlen(context->answer);
        for(int i = len ; i >= 0; i--){
            context->answer[i+1] = context -> answer[i];
        }
        context->answer[0] = '-';
    }else{
        itoa(newInput,context->answer,context->toBase);
    }
}

void doConvert(struct AppContext* context){
    doValid(context);
    fromTen_to_ToBase(context);
}

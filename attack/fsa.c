#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void vulnerableFunction(char *userInput){
    printf("%s",userInput);
}
int main(){
    char input[10];
    printf("Enter some text: ");
    fgets(input, sizeof(input),stdin);
    vulnerableFunction(input);
    return 0;
}
//format string attack: gcc -fno-stack-protector -z execstack -Wno-format-security -no-pie  format.c -o format

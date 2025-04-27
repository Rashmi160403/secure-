#include <stdio.h>
#include <string.h>
void vulnerableFunction(char * input){
    char buffer[10];
    strcpy(buffer,input);
    printf("%p", &buffer);
    printf("\nInput: ");
    printf("%s\n",buffer);
}
int main(){
    char maliciousInput[]="\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    vulnerableFunction(maliciousInput);
    printf("Last Line");
    return 0;
}

//1. sudo sysctl -w kernel.randomize_va_space=0
//2. gcc -fno-stack-protector -z  execstack -g  buffer.c -o buffer
//3. gdb buffer -> b vulnerableFunction -> run -> p $rbp -> p &buffer -> p diff between te

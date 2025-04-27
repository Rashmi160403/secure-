#include<stdio.h>
#include<string.h>

int vul_func(char * str){
	char buffer[50];
	strcpy(buffer,str);
	return 1;
}
int main(int argc, char **argv){
	char str[240];
	FILE *badfile;
	badfile = fopen("badfile", "r");
	fread(str, sizeof(char),200,badfile);
	vul_func(str);
	
	printf("returned properly");
	return 1;
}

//1. sudo sysctl -w kernel.randomize_va_space=0
//2. gcc -fno-stack-protector -z noexecstack -g stack.c -o stack
//3. sudo chown root stack
//4. sudo chmod 4755 stack
//5. >badfile
//6. cat badfile, file should be empty
//7. gdb stack -> run -> p system -> p exit -> quit
//8. gcc -o envsh envsh.c
//9. ./envsh
//10. export MYSHELL="/bin/sh"
//11. ./envsh
//12. now paste the address in the 1st field of exploit.c file
//13. gdb stack -> b vul_func -> run -> p $rbp [on windows] or p $x29 on mac -> p &buffer -> subtract these both -> quit after you get a no. 
//14. now +12 for binsh, +8 for exit and +4 for system in exploit.c file
//15. gcc -o exploit exploit.c
//16. ./exploit
//17. ./stack





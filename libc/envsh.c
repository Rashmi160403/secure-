#include<stdio.h>
#include<stdlib.h>
int main(){
	char *shell = getenv("MYSHELL");
	
	if(shell)
	{
		printf("Value: %s\n",shell);
		printf("Address: %p\n",(void *)shell);
	}
	return 1;
}

// address: system 0xfffff7e3cec4
// address: exit 0xfffff7e2f2f0
// address: bin/sh 0x7fffffffe46e

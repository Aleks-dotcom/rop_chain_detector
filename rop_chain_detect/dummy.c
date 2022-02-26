#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>

void super_sleep(){

	int cnt =0;
	while (cnt >0){
		cnt++;
	}
}


int main(int argc, char ** argv)
{   
	for (int i = 0; i< 1000000;++i)
	{
		printf("%d\n",i);
		sleep(0.1);
	}
	return 0; 
}

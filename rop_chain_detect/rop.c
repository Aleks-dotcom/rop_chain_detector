#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>

int main(int argc, char ** argv)
{   
    pid_t traced_process;
    struct user_regs_struct regs;
    long ins;
    
    if(argc != 2) {
        printf("Usage: %s <pid to be traced>\n",
               argv[0], argv[1]);
        exit(1);
    }
    traced_process = atoi(argv[1]);
    ptrace(PTRACE_ATTACH, traced_process, NULL,NULL);
    long long cnt = 0;
    while (1){
    	if (cnt % 25 == 0){
    		ptrace(PTRACE_SINGLESTEP, traced_process,NULL, NULL);
    		ptrace(PTRACE_GETREGS, traced_process,NULL, &regs);
    		ins = ptrace(PTRACE_PEEKTEXT, traced_process, regs.rip, NULL);
    		printf("RIP: %lx Instruction executed: %lx\n",regs.rip, ins);
    		//ptrace(PTRACE_CONT, traced_process,NULL, NULL);
	}
	cnt++;
    }
    return 0;

}

#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{

  int PScheduler(void);
  int Inheritence(void);
  printf(1, "\n This program tests the correctness of your lab#2\n");

  if (atoi(argv[1]) == 1)
  	PScheduler();
  else if (atoi(argv[1]) == 2)
        Inheritence();
  else 
    printf(1, "\ntype \"lab1 1\" to test exit and wait, \"lab1 2\" to test waitpid \n");
  
  return 0;
 }
  
    
int PScheduler(void){
   // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 63
   // 0 is the highest priority. All processes have a default priority of 20 

  int pid, exit_status;
  int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i <  3; i++) {
	pid = fork();
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {

		setpriority(30-10*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<10000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with priority %d has finished! \n",getpid(),30-10*i);		
		exit(0);
             }
        else {
			printf(2," \n Error \n");
			
             }
	}

	if(pid > 0) {
		for (i = 0; i <  3; i++) {
			//printf(1,"parent %d waiting with priority %d",pid, getpriority());
			wait(&exit_status);
		}
                printf(1,"\n if processes with highest priority finished first then its correct \n");
	}		
	return 0;
}

int Inheritence(void)
{
  printf(1, "\n Tests priority inheritence using wait\n");
  setpriority(0);
  return 1;
}

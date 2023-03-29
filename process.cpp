// /*
// 让僵尸进程的父进程来回收，父进程每隔一段时间来查询子进程是否结束并回收，
// 调用wait()或者waitpid(),通知内核释放僵尸进程
// */
 
// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<stdlib.h>
// #include<sys/wait.h>
// int main(void)
// {
// 	pid_t pid=fork();
// 	int n=0;
// 	char *s=NULL;
// 	if(pid<0){
// 		perror("fork creat ");
// 	}else if(pid>0){//父进程
// 		n=1;
// 		s="this is parent process";
// 	}else{//pid=0//子进程
// 		n=10;
// 		s="this is child process";
// 	}
// 	for(int i=0;i<n;++i){
// 		printf("%s\n",s);
// 		if(pid>0){	
// 			printf("i am waiting for you ,my child\n");
// 			wait(NULL);	
// 		}
// 		sleep(1);
// 	}
// 	printf("%s bye\n",s);
// 	return 0;
// }
/*
采用信号SIGCHLD通知处理，并在信号处理程序中调用wait函数
*/
 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <signal.h>
void signal_wait(int isig)
{
	wait(NULL);
	printf("child is cleaned\n");
}
int main(void)
{
	pid_t pid=fork();
	char *s=NULL;
	if(signal(SIGCHLD,signal_wait)==SIG_ERR){
		perror("install signal_wait");
	}
	if(pid<0){
		perror("fork creat ");
	}else if(pid>0){//父进程
		sleep(1);
		s="this is parent process";
	}else{//pid=0//子进程
		s="this is child process";
	}
	printf("%s bye\n",s);
	return 0;
}
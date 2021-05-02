#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

	int numPrime(int no){
		 int i,cnt = 0;
	for(i = 2; i <= no/2; i++)
	{
	if(no%i == 0){
		cnt++;
		break;
	}
	}
		return cnt;
}
	int main(){
	int i, no, cnt = 0;
	int buffer;
	int fd[2];
	if(pipe(fd) == -1){
		printf("Error");
		return 1;
	}

	int id = fork();
	if(id == 0){
	close(fd[0]);
	printf("Input a number: ");
	scanf("%d", &no);
	write(fd[1],&no,sizeof(no));
	close(fd[1]);
}else{

	close(fd[1]);	
	read(fd[0],&buffer,sizeof(buffer));
	close(fd[0]);
	cnt = numPrime(buffer);
	if(cnt == 0 && buffer != 1)
	{
		printf("%d is a prime number\n",buffer);
	}
	else{
		printf("%d is not a prime number\n",buffer);
	}
	

	return EXIT_SUCCESS;
}

	return 0;
}


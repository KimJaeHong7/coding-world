#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char **argv){
	char cmd[1000];
	char *token[1000];
	char *token_s[1000];
	int status;
	int i = 0;
	int j = 0;
	int cnt = 0;
	int num = 0;
	pid_t pid[1000];
	pid_t ter;
	//interactive mode
	if(argc==1){
		while(!feof(stdin)){
			cnt=0;
			printf("prompt> ");
			if(fgets(cmd,sizeof(cmd),stdin)==NULL)
				exit(0);
			while(cmd[cnt]!='\0'){
				if(cmd[cnt]=='\n')
					cmd[cnt]='\0';
				cnt++;
			}
			if(strcmp(cmd,"quit")==0)
				exit(0);
			token[i] = strtok(cmd,";");
			while(token[i]!=NULL){
				token[++i] = strtok(NULL,";");
			}
			while(token[j]!=NULL){
				pid[num++]=fork();
				cnt=0;
				if(pid[num-1]==0){
				token_s[cnt] = strtok(token[j]," ");
				while(token_s[cnt]!=NULL){
					token_s[++cnt]=strtok(NULL," ");
				}
				token_s[cnt]=NULL;
				if(execvp(token_s[0],token_s)==-1){
					printf("exec error!\n");
					exit(-1);
				}
				}
				else if(pid[num-1]==-1){
					printf("fork error!\n");
					exit(-1);
				}
				j++;
			}
			for(int m = 0; m<i;m++){
				if(pid[m]>0){
					ter = wait(&status);
					if(!WIFEXITED(status)){
						printf("Child %d has terminated abnormally\n",ter);
					}
				}
			}
		}
	}
	//Batch mode
	else if(argc==2){
		FILE *fp;
		fp=fopen(argv[1],"r");
		if(fp==NULL){
			printf("File open error!\n");
		}
		else{
			while(!feof(fp)){
				cnt = 0;
				if (fgets(cmd, sizeof(cmd), fp) == NULL)
					exit(0);
				while (cmd[cnt] != '\0') {
					if (cmd[cnt] == '\n')
						cmd[cnt] = '\0';
					cnt++;
				}
				printf("%s\n",cmd);
				if (strcmp(cmd, "quit") == 0)
					exit(0);
				token[i] = strtok(cmd, ";");
				while (token[i] != NULL)
					token[++i] = strtok(NULL, ";");
				while (token[j] != NULL) {
					pid[num++] = fork();
					cnt = 0;
					if (pid[num-1] == 0) {
						token_s[cnt] = strtok(token[j], " ");
						while (token_s[cnt] != NULL) {
							token_s[++cnt] = strtok(NULL, " ");
						}
						token_s[cnt] = NULL;
						if (execvp(token_s[0], token_s) == -1) {
							printf("exec error!\n");
							exit(-1);
						}
					}
					else if (pid[num-1] == -1) {
						printf("fork error!\n");
						exit(-1);
					}
					j++;
				}
				for(int m = 0; m<i;m++){
					if(pid[m]>0){
						ter = wait(&status);
						if(!WIFEXITED(status))
							printf("Child %d has terminated abnormally\n",ter);
					}
				}
			}
		}
		fclose(fp);
	}
	else
		printf("Wrong input!\n");
	return 0;
}

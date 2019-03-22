#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include </home/axilleas/Documents/Database_with_C/types.h>
#include </home/axilleas/Documents/Database_with_C/age.h>
#include </home/axilleas/Documents/Database_with_C/idgen.h>


int main(void){

	char *ANSWER;

	FILE *fdatabase;

	int reRegister = -1;
	int i = 0;

	char c;

	ANSWER = malloc(8*(sizeof(char)));
	if(ANSWER == NULL)
		printf("error");

	printf("Do you want to 'Register' or 'View' the Database?: ");
	scanf("%s", ANSWER);
	//printf("%s\n", ANSWER);
	if(strcmp(ANSWER, "View")==0 || strcmp(ANSWER, "view") == 0 || strcmp(ANSWER, "VIEW") == 0 || strcmp(ANSWER, "vIEW") == 0){
		fdatabase = fopen("/home/axilleas/Documents/Database_with_C/database.txt", "r");
		printf("\n***database.txt***\n");
		while((c=fgetc(fdatabase)) != EOF){
			printf("%c", c);
		}
	}

	if(strcmp(ANSWER, "Register") == 0 || strcmp(ANSWER, "register") == 0 || strcmp(ANSWER, "REGISTER") == 0 || strcmp(ANSWER, "rEGISTER") == 0){
		fdatabase = fopen("/home/axilleas/Documents/Database_with_C/database.txt", "a");
		reRegister = -1;
		while(i!=reRegister){
			printf("\nPlease type your First and your Last name: ");
			scanf("%s%s", registration[i].FirstName, registration[i].LastName);

			registration[i].age = AgeInput();
			if (registration[i].age>=18 && registration[i].age <= 125){
				printf("Type your country: ");
				scanf("%s", registration[i].country);
				registration[i].PrimaryKey = IDGen();
				printf("\nThanks for using our service.\nThis is your ID for our service: %d.\n", registration[i].PrimaryKey);
				printf("And this is your registration log:\n[ID: %d - [%s %s] - %d - (%s)]\n", registration[i].PrimaryKey, registration[i].FirstName, registration[i].LastName, registration[i].age, registration[i].country);
				fprintf(fdatabase, "[ID: %d - [%s %s] - %d - (%s)]\n", registration[i].PrimaryKey, registration[i].FirstName, registration[i].LastName, registration[i].age, registration[i].country);

			}
			else{
				while(registration[i].age<18 || registration[i].age > 125){
					printf("\nYou are not an adult!\nYou have to be 18+ in order to register into our Database.\n");
					registration[i].age = AgeInput();
					if (registration[i].age>=18 && registration[i].age <= 125){
						printf("Type your country: ");
						scanf("%s", registration[i].country);
						registration[i].PrimaryKey = IDGen();
						printf("\nThanks for using our service.\nThis is your ID for our service: %d.\n", registration[i].PrimaryKey);
						printf("And this is your registration log:\n[ID: %d - [%s %s] - %d - (%s)]\n", registration[i].PrimaryKey, registration[i].FirstName, registration[i].LastName, registration[i].age, registration[i].country);
						fprintf(fdatabase, "[ID: %d - [%s %s] - %d - (%s)]\n", registration[i].PrimaryKey, registration[i].FirstName, registration[i].LastName, registration[i].age, registration[i].country);
					}
				}
			}
			printf("\nDo you want to register again?: ");
			scanf("%s", ANSWER);
			if (strcmp(ANSWER, "Yes") == 0 ||strcmp(ANSWER, "YES") == 0 || strcmp(ANSWER, "yes") == 0 || strcmp(ANSWER, "yes") == 0 || strcmp(ANSWER, "yES") == 0 || strcmp(ANSWER, "y") == 0 || strcmp(ANSWER, "Y") == 0){
				i++;
				pplRegd = i;
				struct Types registration[pplRegd];
				continue;
			}
			else
				i = -1;
		}
	}
	for(i = 0;i<=pplRegd;i++){
		printf("\n[ID: %d - [%s %s] - %d - (%s)]\n", registration[i].PrimaryKey, registration[i].FirstName, registration[i].LastName, registration[i].age, registration[i].country);
	}
	fclose(fdatabase);

	free(ANSWER);
}
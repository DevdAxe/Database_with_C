#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include </home/axilleas/Documents/Database_with_C/types.h>


int main(void){

	struct Types registration;

	char *ANSWER;

	ANSWER = malloc(8*(sizeof(char)));
	if(ANSWER == NULL)
		printf("error");

	printf("Do you want to 'Register' or 'View' the Database?: ");
	scanf("%s", ANSWER);
	//printf("%s\n", ANSWER);

	if(strcmp(ANSWER, "Register") == 0 || strcmp(ANSWER, "register") == 0 || strcmp(ANSWER, "REGISTER") == 0){
		printf("\nPlease type your First and your Last name: ");
		scanf("%s%s", registration.FirstName, registration.LastName);

		srand(time(NULL));
		printf("Type your age: ");
		scanf("%d", &registration.age);
		if (registration.age>=18 && registration.age <= 125){
			printf("Type your country: ");
			scanf("%s", registration.country);
			registration.PrimaryKey = rand()%100000+000001;
			printf("\nThanks for using our service.\nThis is your ID for our service: %d.\n", registration.PrimaryKey);
			printf("And this is your registration log:\n[ID: %d - [%s %s] - %d - (%s)]\n", registration.PrimaryKey, registration.FirstName, registration.LastName, registration.age, registration.country);
		}
		else{
			while(registration.age<18 || registration.age > 125){
				printf("\nYou are not an adult!\nYou have to be 18+ in order to register into our Database.\n");
				printf("Type your age: ");
				scanf("%d", &registration.age);
				if (registration.age>=18 && registration.age <= 125){
					printf("Type your country: ");
					scanf("%s", registration.country);
					printf("\nThanks for using our service.\n");
					registration.PrimaryKey = rand()%100000+000001;
					printf("\nThanks for using our service.\nThis is your ID for our service: %d.\n", registration.PrimaryKey);
					printf("And this is your registration log:\n[ID: %d - [%s %s] - %d - (%s)]\n", registration.PrimaryKey, registration.FirstName, registration.LastName, registration.age, registration.country);
				}
			}
		}
		



	}

	free(ANSWER);
}


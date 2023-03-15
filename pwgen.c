#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void generate();

int main()
{
	printf("\t\t\t\t\t\t============================\n");
	printf("\t\t\t\t\t\tWelcome to the P/W Generator\n");
	printf("\t\t\t\t\t\t============================\n\n");
	generate();
	printf("\t\t\t\t\t\t============================\n");
	printf("\t\t\t\t\t\t          File Saved        \n");
	printf("\t\t\t\t\t\t============================\n\n");

	return (0);
}

void generate()
{
	int length;
	char name[10];
	char description[100];
	char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*()_-+=QWERTYUIOPASDFGHJKLZXCVBNM[]{};':\"<>,.?/|\\";
	do
	{
	printf("Enter the name of the service: ");
	fgets(name, 20, stdin);
	if(isalpha(name[0]) == 0)
		printf("Name must start with a charachter\n");
	} while(isalpha(name[0]) == 0);
	printf("Enter a short description (100 charcs max): ");
	fgets(description, 100, stdin);
	printf("Password length: ");
	scanf("%d", &length);
	FILE *ptr;
	int i;
	srand(time(NULL));
	char filename[10];
	strcpy(filename, name);
	filename[strcspn(filename, "\n")] = 0;
	strcat(filename, ".txt");	
	ptr = fopen(filename, "w");
	fprintf(ptr, "name: %s\ndescription: %s\nlength: %d\n", 
			name, description, length);
	fprintf(ptr, "Your Generated Password is: ");
	for(i = 0; i < length; i++)
	{
		fprintf(ptr, "%c", list[rand() % (sizeof list - 1)]);
	}
	fprintf(ptr, "\n");
	fclose(ptr);
}

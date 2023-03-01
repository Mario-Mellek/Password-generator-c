#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
	printf("Enter the name of the service: ");
	fgets(name, 20, stdin);
	printf("Enter a short description (100 charcs max): ");
	fgets(description, 100, stdin);
	printf("Password length: ");
	scanf("%d", &length);
	FILE *ptr;
	int i;
	srand(time(NULL));
	name[strcspn(name, "\n")] = 0;
	strcat(name, ".txt");
	ptr = fopen(name, "w");
	fprintf(ptr, "name: %s\ndescription: %s\nlength: %d\n", 
			name, description, length);
	fprintf(ptr, "Your Generated Password is: ");
	for(i = 0; i < length; i++)
	{
		fprintf(ptr, "%c", list[rand() % (sizeof list - 1)]);
	}
	putchar('\n');
	fclose(ptr);
}

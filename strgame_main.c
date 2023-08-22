#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "strgame_header.h"


int main()
{
	char name[20];
	int user_choice=0;
	printf("\033[0;33m");
	printf("\n\t=========Welcome to the game=========\n");
	printf("\033[0m");
	printf("\nEnter your name : ");
	scanf("%s",name);
	printf("\n####  Hi %s, Let's start the game  ####\n",name);
	printf("\nGenerating Table For You.....\n");
	srand(time(NULL));
	int *user_num=random_create();
	int **user_table=create_table(user_num);
	printf("\n ===== YOUR TABLE FOR GAMEPLAY =====\n");
	print_table(user_table);
	printf("\nGenerating Table For Me....\n");
	int *sys_num=random_create();
	int **sys_table=create_table(sys_num);
	printf("\n\nEnter the number b/w 1 to 25 \n");
	while (true)
	{
		printf("\nYour choice : ");
		scanf("%d",&user_choice);
		printf("\n");
		int check = verify_user_choice(user_choice,user_num);
		if (check == 1)
		{
			strike_num(user_choice,user_num);
			strike_num(user_choice,sys_num);
			user_table=create_table(user_num);
			sys_table=create_table(sys_num);
			print_table(user_table);
			int user_check1=check_points(user_table);
			int sys_check1=check_points(sys_table);
			int result1=game_result(user_check1,sys_check1);
			if(result1==1 || result1 ==2)
			{
				printf("\n\t=== SYSTEM TABLE ===\n");
				print_table(sys_table);
			        break;
			}
			printf("\033[0;33m");
			printf("\nNice !, Now it's my turn....\n");
			printf("\033[0m");
			int sys_choice=sys_random_choice(sys_num);
			printf("\nMy choice is : %d\n",sys_choice);
			strike_num(sys_choice,sys_num);
			strike_num(sys_choice,user_num);
			sys_table=create_table(sys_num);
			user_table=create_table(user_num);
			print_table(user_table);
			int user_check=check_points(user_table);
			int sys_check=check_points(sys_table);
			int result2=game_result(user_check,sys_check);
			if(result2==1 || result2 ==2)
			{
				printf("\n\t=== SYSTEM TABLE ===\n");
				print_table(sys_table);
			        break;
			}
		}
		else
		{
			printf("\n\nPlease enter the valid number...\n");
			
		}
	
	}

	free(user_num);
	free(sys_num);
	free(user_table);
	free(sys_table);
}

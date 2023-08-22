#ifndef _STRGAME_HEADER_H
#define _STRGAME_HEADER_H

int *random_create();
int **create_table(int *arr);
void print_table(int **arr);
int verify_user_choice(int num,int *arr);
void strike_num(int num,int *arr);
int sys_random_choice(int *arr);
int check_points(int **arr);
int game_result(int ,int);
#endif

#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

//Function declarations
void disp_intro(void);
void disp_menu(void);
void disp_rules(void);
void disp_scores(int sec[]);
void disp_die(int die_val[]);
void disp_ask_reroll(void);
void invld_inpt(void);

void roll_dice(int die[], int index);
void disp_combos(void);
void sort(int die[]);
void ask_which_die();
void re_die(int die[], int reroll_die);
void reroll(int num_die, int die[]);
int total_score(int sec[]);
int is_add_points(int sec[], int tot_num);
int replay(void);

void combo1(int die[], int sec[]);
void combo2(int die[], int sec[]);
void combo3(int die[], int sec[]);
void combo4(int die[], int sec[]);
void combo5(int die[], int sec[]);
void combo6(int die[], int sec[]);
void combo7(int die[], int sec[]);
void combo8(int die[], int sec[]);
void combo9(int die[], int sec[]);
void combo10(int die[], int sec[]);
void combo11(int die[], int sec[]);
void combo12(int die[], int sec[]);
void decide_combo(int combo, int die[], int sec[]);

#endif
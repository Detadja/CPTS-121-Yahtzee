#include "header.h"

//Displays the introductions to the game.
void disp_intro(void)
{
	printf("-----------------------\n");
	printf("| Welcome to Yahtzee! |\n");
	printf("-----------------------\n\n");
}

//Displays the menu and the choices to proceed.
void disp_menu(void)
{
	printf("--------------------\n");
	printf("| 1. Play Game     |\n");
	printf("| 2. Display Rules |\n");
	printf("| 3. Exit          |\n");
	printf("--------------------\n\n");
}

//Displays the game rules.
void disp_rules(void)
{
	system("cls");
	printf("----------------------------------------------------------------------------\n");
	printf("| In this game, there will be two players facing aginst each other.        |\n");
	printf("| Both of you will roll 5 die in turns, and the combinations of the        |\n");
	printf("| five values of the upward faces of each die will represent your          |\n");
	printf("| points. You will then pick a combination out of 13, which best           |\n");
	printf("| represents the values you have.                                          |\n");
	printf("|                                                                          |\n");
	printf("| But don't worry, for each player can roll up to three times each         |\n");
	printf("| round. Meaning, you can reroll up to two more times before               |\n");
	printf("| picking. Additionally, when you think you have a bad roll, you           |\n");
	printf("| may pick which ones you want to keep, or to reroll, so don't             |\n");
	printf("| worry if the RNG gods didn't bless you today!                            |\n");
	printf("|                                                                          |\n");
	printf("| Another thing to note is that when you've picked a combination,          |\n");
	printf("| think of it as a single slot. Once you've picked one, you can't          |\n");
	printf("| pick it again. This is important, so don't forget it!                    |\n");
	printf("|                                                                          |\n");
	printf("| The possible combinations are:                                           |\n");
	printf("| 1. Ones (The sum of all the die which have a value of 1)                 |\n");
	printf("| 2. Twos (The sum of all the die which have a value of 2)                 |\n");
	printf("| 3. Threes (The sum of all the die which have a value of 3)               |\n");
	printf("| 4. Fours (The sum of all the die which have a value of 4)                |\n");
	printf("| 5. Fives (The sum of all the die which have a value of 5)                |\n");
	printf("| 6. Sixes (The sum of all the die which have a value of 6)                |\n");
	printf("| 7. Three-of-a-kind (Three dice with the same face/number)                |\n");
	printf("| 8. Four-of-a-kind (Four dice with the same face/number)                  |\n");
	printf("| 9. Full House (A pair of die with the same face/number and three die     |\n");
	printf("| with the same face/number)                                               |\n");
	printf("| 10. Small Straight (A sequence of four die)                              |\n");
	printf("| 11. Large Straight (A sequence of five die)                              |\n");
	printf("| 12. Yahtzee (Five die with the same face/number)                         |\n");
	printf("| 13. Chance (Add all dice face values regardless of possible combination) |\n");
	printf("|                                                                          |\n");
	printf("| Both of you will play for 13 rounds, and naturally, the one with the     |\n");
	printf("| most points by the end wins.                                             |\n");
	printf("----------------------------------------------------------------------------\n\n");
}

//Display's the player's scores.
void disp_scores(int player, int sec[])
{
	printf("-------------------------------------\n");
	printf("| Player %d, your scores are:        |\n", player);
	printf("-------------------------------------\n");
	printf("|      Choice      |     Score      |\n");
	printf("-------------------------------------\n");
	printf("|       Ones       |       %d        |\n", sec[0]);
	printf("|       Twos       |       %d       |\n", sec[1]);
	printf("|      Threes      |       %d       |\n", sec[2]);
	printf("|       Fours      |       %d       |\n", sec[3]);
	printf("|       Fives      |       %d       |\n", sec[4]);
	printf("|       Sixes      |       %d       |\n", sec[5]);
	printf("|  Three-of-a-kind |       %d       |\n", sec[6]);
	printf("|  Four-of-a-kind  |       %d       |\n", sec[7]);
	printf("|    Full House    |       %d       |\n", sec[8]);
	printf("|  Small Straight  |       %d       |\n", sec[9]);
	printf("|  Large Straight  |       %d       |\n", sec[10]);
	printf("|      Yahtzee     |       %d       |\n", sec[11]);
	printf("|      Chance      |       %d       |\n", sec[12]);
	printf("-------------------------------------\n");
}

//Displays the player's current die/roll.
void disp_die(int die[])
{
	printf("---------------------------------------\n");
	printf("| Your rolls are: | %d | %d | %d | %d | %d |\n", die[0], die[1], die[2], die[3], die[4]);
	printf("---------------------------------------\n");
}

//Displays a message asking the player whether they want to reroll or not.
void disp_ask_reroll(void)
{
	printf("--------------------------------------------------------------------------\n");
	printf("| You can still reroll. Do you want to keep your roll (Y) or reroll (N)? |\n");
	printf("--------------------------------------------------------------------------\n");
}

//Displays the invalid input message.
void invld_inpt(void)
{
	printf("----------------------------\n");
	printf("| That's not valid choice. |\n");
	printf("----------------------------\n\n");
}

//Rolls a die and puts it into a specific index for a specific array.
void roll_dice(int die[], int index)
{
	die[index] = (rand() % 6) + 1;
}

//Displays the combination list for the player to decide, which one fits their roll the best.
void disp_combos(void)
{
	printf("----------------------------------------------------------------------------\n");
	printf("| 1. Ones (The sum of all the die which have a value of 1)                 |\n");
	printf("| 2. Twos (The sum of all the die which have a value of 2)                 |\n");
	printf("| 3. Threes (The sum of all the die which have a value of 3)               |\n");
	printf("| 4. Fours (The sum of all the die which have a value of 4)                |\n");
	printf("| 5. Fives (The sum of all the die which have a value of 5)                |\n");
	printf("| 6. Sixes (The sum of all the die which have a value of 6)                |\n");
	printf("| 7. Three-of-a-kind (Three dice with the same face/number)                |\n");
	printf("| 8. Four-of-a-kind (Four dice with the same face/number)                  |\n");
	printf("| 9. Full House (A pair of die with the same face/number and               |\n");
	printf("| three die with the same face/number)                                     |\n");
	printf("| 10. Small Straight (A sequence of four die)                              |\n");
	printf("| 11. Large Straight (A sequence of five die)                              |\n");
	printf("| 12. Yahtzee (Five die with the same face/number)                         |\n");
	printf("| 13. Chance (Add all dice face values regardless of possible combination) |\n");
	printf("----------------------------------------------------------------------------\n\n");
}

//Sorts the dice array (size 5) of a player in order.
void sort(int die[])
{
	int temp = 0;

	for (int iter = 1; iter < 5; iter++)
	{
		for (int index = 0; index < 5 - iter; index++)
		{
			if (die[index] >= die[index + 1])
			{
				temp = die[index];
				die[index] = die[index + 1];
				die[index + 1] = temp;
			}
		}
	}
}

//Asks the player, which die they want to reroll (1-5).
void ask_which_die()
{
	printf("-----------------------------------------\n");
	printf("| Which dice/die do you want to reroll? |\n");
	printf("-----------------------------------------\n");

}

//Rerolls the selected die.
void re_die(int die[], int reroll_die)
{
	if (reroll_die == 1)
	{
		roll_dice(die, 0);
	}
	else if (reroll_die == 2)
	{
		roll_dice(die, 1);
	}
	else if (reroll_die == 3)
	{
		roll_dice(die, 2);
	}
	else if (reroll_die == 4)
	{
		roll_dice(die, 3);
	}
	else if (reroll_die == 5)
	{
		roll_dice(die, 4);
	}
	else
	{
		roll_dice(die, 5);
	}
}

//Determines how many die the player wants to roll, which die to roll, and rerolls them.
void reroll(int num_die, int die[])
{
	if (num_die == 1) //The player chose to reroll 1 die.
	{
		int reroll_die = 0;
		system("cls");
		ask_which_die();
		disp_die(die);
		scanf("%d", &reroll_die);
		while (reroll_die < 1 || reroll_die > 6) //Checks for invalid input.
		{
			system("cls");
			invld_inpt();
			ask_which_die();
			disp_die(die);
			scanf("%d", &reroll_die);
		}
		//Rerolls the die.
		re_die(die, reroll_die);
	}
	else if (num_die == 2) //The player chose to reroll 2 die.
	{
		int reroll_die1 = 0, reroll_die2 = 0;
		system("cls");
		ask_which_die();
		disp_die(die);
		scanf("%d%d", &reroll_die1, &reroll_die2);
		while (reroll_die1 < 1 || reroll_die1 > 6 || reroll_die2 < 1 || reroll_die2 > 6) //Checks for invalid input.
		{
			system("cls");
			invld_inpt();
			ask_which_die();
			disp_die(die);
			scanf("%d%d", &reroll_die1, &reroll_die2);
		}
		//Rerolls the die.
		re_die(die, reroll_die1);
		re_die(die, reroll_die2);
	}
	else if (num_die == 3) //The player chose to reroll 3 die.
	{
		int reroll_die1 = 0, reroll_die2 = 0, reroll_die3 = 0;
		system("cls");
		ask_which_die();
		disp_die(die);
		scanf("%d%d%d", &reroll_die1, &reroll_die2, &reroll_die3); 
		while (reroll_die1 < 1 || reroll_die1 > 6 || reroll_die2 < 1 || reroll_die2 > 6 || reroll_die3 < 1 || reroll_die3 > 6) //Checks for invalid input.
		{
			system("cls");
			invld_inpt();
			ask_which_die();
			scanf("%d%d%d", &reroll_die1, &reroll_die2, &reroll_die3);
		}
		//Rerolls the die.
		re_die(die, reroll_die1);
		re_die(die, reroll_die2);
		re_die(die, reroll_die3);
	}
	else if (num_die == 4) //The player chose to reroll 4 die.
	{
		int reroll_die1 = 0, reroll_die2 = 0, reroll_die3 = 0, reroll_die4 = 0;
		system("cls");
		ask_which_die();
		disp_die(die);
		scanf("%d%d%d%d", &reroll_die1, &reroll_die2, &reroll_die3, &reroll_die4);
		while (reroll_die1 < 1 || reroll_die1 > 6 || reroll_die2 < 1 || reroll_die2 > 6 || reroll_die3 < 1 || reroll_die3 > 6 || reroll_die4 < 1 || reroll_die4 > 6) //Checks for invalid input.
		{
			system("cls");
			invld_inpt();
			ask_which_die();
			scanf("%d%d%d%d", &reroll_die1, &reroll_die2, &reroll_die3, &reroll_die4);
		}
		//Rerolls the die.
		re_die(die, reroll_die1);
		re_die(die, reroll_die2);
		re_die(die, reroll_die3);
		re_die(die, reroll_die4);
	}
	else  //The player chose to reroll all die.
	{
		for (int index = 0; index < 5; index++)
		{
			roll_dice(die, index); //Rerolls the die.
		}
	}
}

//Determines the total score.
int total_score(int sec[])
{
	int total = 0;
	total = sec[0] + sec[1] + sec[2] + sec[3] + sec[4] + sec[5] + sec[6] + sec[7] + sec[8] + sec[9] + sec[10] + sec[11] + sec[12];
	return total;
}

//Determines whether the total score of the upper section is equal to or greater than 63, then adds 35 to the total points if so.
int is_add_points(int sec[], int tot_score)
{
	int total_usec = 0, total_score = 0;
	total_usec = sec[0] + sec[1] + sec[2] + sec[3] + sec[4] + sec[5];
	if (total_usec >= 63)
	{
		total_score = tot_score + 35;
		return total_score;
	}
	else
		return tot_score;
}

//Asks the player if they want to replay or not.
int replay(void)
{
	int check = 0;
	char choice = '\0';
	printf("--------------------------------------\n");
	printf("| Do you want to play again (Y | N)? |\n");
	printf("--------------------------------------\n");
	scanf(" %c", &choice);

	if (choice == 'y' || choice == 'Y')
	{
		return 1;
	}
	else if (choice == 'n' || choice == 'N')
	{
		return 3;
	}
	else
	{
		system("cls");
		invld_inpt();
		return 4;
	}
}

//Check if the player's die array is valid for the 1st combination choice (Ones).
void combo1(int die[], int sec[])
{
	int index = 0, count = 0;
	while (index < 5)
	{
		if (die[index] == 1)
		{
			count++;
		}
		index++;
	}
	sec[0] = count;
}

//Check if the player's die array is valid for the 2nd combination choice (Twos).
void combo2(int die[], int sec[])
{
	int index = 0, count = 0;
	while (index < 5)
	{
		if (die[index] == 2)
		{
			count++;
		}
		index++;
	}
	sec[1] = count * 2;
}

//Check if the player's die array is valid for the 3rd combination choice (Threes).
void combo3(int die[], int sec[])
{
	int index = 0, count = 0;
	while (index < 5)
	{
		if (die[index] == 3)
		{
			count++;
		}
		index++;
	}
	sec[2] = count * 3;
}

//Check if the player's die array is valid for the 4th combination choice (Fours).
void combo4(int die[], int sec[])
{
	int index = 0, count = 0;
	while (index < 5)
	{
		if (die[index] == 4)
		{
			count++;
		}
		index++;
	}
	sec[3] = count * 4;
}

//Check if the player's die array is valid for the 5th combination choice (Fives).
void combo5(int die[], int sec[])
{
	int index = 0, count = 0;
	while (index < 5)
	{
		if (die[index] == 5)
		{
			count++;
		}
		index++;
	}
	sec[4] = count * 5;
}

//Check if the player's die array is valid for the 6th combination choice (Sixes).
void combo6(int die[], int sec[])
{
	int index = 0, count = 0;
	while (index < 6)
	{
		if (die[index] == 6)
		{
			count++;
		}
		index++;
	}
	sec[5] = count * 6;
}

//Check if the player's die array is valid for the 7th combination choice (Three-of-a-kind).
void combo7(int die[], int sec[])
{
	int num = 0, count = 0, temp = 0;
	temp = die[num];
	for (int index = num; index < 5; index++)
	{
		if (die[index] == temp)
		{
			count++;
		}
		if (count == 3)
		{
			sec[6] = die[0] + die[1] + die[2] + die[3] + die[4];
		}
	}
}

//Check if the player's die array is valid for the 8th combination choice (Four-of-a-kind).
void combo8(int die[], int sec[])
{
	int num = 0, count = 0, temp = 0;
	temp = die[num];
	for (int index = num; index < 5; index++)
	{
		if (die[index] == temp)
		{
			count++;
		}
		if (count == 4)
		{
			sec[7] = die[0] + die[1] + die[2] + die[3] + die[4];
		}
	}
}

//Check if the player's die array is valid for the 9th combination choice (Full House).
void combo9(int die[], int sec[])
{
	int num = 0, num2 = 0, temp = 0, count = 0, count2 = 0;
	sort(die);

	temp = die[num];
	for (int index = num; index < 5; index++)
	{
		if (die[index] == temp)
		{
			count++;
		}
	}

	if (count == 2)
	{
		while (num2 < 5)
		{
			temp = die[num2 + 2];
			for (int index = num2 + 2; index < 5; index++)
			{
				if (die[index] == temp)
				{
					count2++;
				}
				if (count2 == 3)
				{
					sec[8] = 25;
				}
			}
			num2++;
		}
	}
	else if (count == 3)
	{
		while (num2 < 5)
		{
			temp = die[num2 + 3];
			for (int index = num2 + 3; index < 5; index++)
			{
				if (die[index] == temp)
				{
					count2++;
				}
				if (count2 == 2)
				{
					sec[8] = 25;
				}
			}
			num2++;
		}
	}
}

//Check if the player's die array is valid for the 10th combination choice (Small Straight).
void combo10(int die[], int sec[])
{
	int count = 0;
	sort(die);
	for (int index = 0; index < 4; index++)
	{
		if (die[index] == index + 1 || die[index] == index + 2 || die[index] == index + 3)
		{
			count++;
		}
	}
	if (count == 4)
	{
		sec[9] = 30;
	}
	else
		sec[9] = 0;
}

//Check if the player's die array is valid for the 11th combination choice (Large Straight).
void combo11(int die[], int sec[])
{
	int count = 0;
	sort(die);
	for (int index = 0; index < 5; index++)
	{
		if (die[index] == index + 1 || die[index] == index + 2)
		{
			count++;
		}
	}
	if (count == 5)
	{
		sec[10] = 40;
	}
	else
		sec[10] = 0;
}

//Check if the player's die array is valid for the 12th combination choice (Yahtzee).
void combo12(int die[], int sec[])
{
	int num = 0, count = 0, temp = 0;

	temp = die[num];
	for (int index = num; index < 5; index++)
	{
		if (die[index] == temp)
		{
			count++;
		}
		if (count == 5)
		{
			sec[11] = 50;
		}
	}

}

//Puts the corresponding score into a specific index in either player 1's other player 2's upper or lower section scores array.
void decide_combo(int combo, int die[], int sec[])
{
	int index = 0, count = 0;
	if (combo == 1) //Upper section 1 (Ones)
	{
		combo1(die, sec);
	}
	else if (combo == 2) //Upper section 2 (Twos)
	{
		combo2(die, sec);
	}
	else if (combo == 3) //Upper section 3 (Threes)
	{
		combo3(die, sec);
	}
	else if (combo == 4)//Upper section 4 (Fours)
	{
		combo4(die, sec);
	}
	else if (combo == 5) //Upper section 5 (FIves)
	{
		combo5(die, sec);
	}
	else if (combo == 6) //Upper section 6 (Sixes)
	{
		combo6(die, sec);
	}
	else if (combo == 7) //Lower section 1 (Three-of-a-kind)
	{
		combo7(die, sec);
	}
	else if (combo == 8) //Lower section 2 (Four-of-a-kind)
	{
		combo8(die, sec);
	}
	else if (combo == 9) //Lower section 3 (Full House: Three of a kind and a pair)
	{
		combo9(die, sec);
	}
	else if (combo == 10) //Lower section 4 (Small Straight: Sequence of four)
	{
		combo10(die, sec);
	}
	else if (combo == 11) //Lower section 5 (Large Straight: Sequence of five)
	{
	    combo11(die, sec);
	}
	else if (combo == 12) //Lower section 6 (Yahtzee: Five of a kind/all have the same face)
	{
		combo12(die, sec);
    }
	else //Lower section 7 (Chance: Add number of die regardless of combination possibilities/or lack thereof)
	{
		sec[12] = die[0] + die[1] + die[2] + die[3] + die[4];
	}
}


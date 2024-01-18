/*
	Name: Denise Tanumihardja
	Class: Cpts 121
	Project: Programming Assignment 5 (PA 5)
	Date: 8 March 2020
	Description: The program runs a game of Yahtzee between two players. It counts and displays the round number, as well as which player is playing at the moment. For each
	             player, 5 die are rolled and they can choose which dice/die they want to reroll (as they can roll up two three times, they can reroll up to two more times).
				 The player can then choose which combination choice (out of 13) to pick depending on their set of 5 die values (with or without rerolling). The scores are then
				 stored in the upper/lower section array, and by the end, the winner (player with most points) is displayed.
*/

#include "header.h"

int main(void)
{		
	int num = 0;
	do
	{
		system("cls");
		disp_intro();
		int round = 1, tot_score1 = 0, tot_score2 = 0;
		int p1_die[] = { 0, 0, 0, 0, 0 }, p1_sec[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int p2_die[] = { 0, 0, 0, 0, 0 }, p2_sec[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		disp_menu(); //Displays the game intro
		scanf("%d", &num);
		while (num < 1 || num > 3) //Checks for invalid input, displays appropriate message, and asks for an input again.
		{
			system("cls");
			invld_inpt();
			disp_menu();
		    scanf("%d", &num);
		}

		switch (num)
		{
		case 1: //Play game.
		{
			srand((unsigned int)time(NULL));
			do
			{
				for (int player = 1; player <= 2; player++)
				{
					system("cls"); //Clears the screen.
					printf("\n------------\n");
					printf("| Round %d! |\n", round); //Displays the round no.
					printf("------------\n");
					printf("\n--------------------\n");
					printf("| Ready, Player %d! |\n", player); //Tells which player's turn it is currently.
					printf("--------------------\n\n");

					if (player == 1) //Determines whose turn it is and displays the player's scores.
						disp_scores(1, p1_sec);
					else
						disp_scores(2, p2_sec);
					
					printf("-------------------------------------------------------\n");
					printf("| Press ENTER key to continue and roll your five die. |\n");
					printf("-------------------------------------------------------\n\n");
					getch(); //Stops program and asks user to press enter.
					if (player == 1) //Determines whether it accesses player 1's or player 2's dice array and displays it to them.
					{
						int index = 0;
						while (index <= 4) //Rolls 5 die and stores it into player 1's die array.
						{
							roll_dice(p1_die, index); //Rolls dice.
							index++;
						}
					}
					else
					{
						int index = 0;
						while (index <= 4) //Rolls 5 die and stores it into player 2's die array.
						{
							roll_dice(p2_die, index); //Rolls dice.
							index++;
						}
					}

					for (int roll = 1; roll < 3; roll++) //Determines if the player has rolled less than or 3 times.
					{
						int check = 0;
						char choice = '\0';
						do //Checks for invalid input.
						{
							if (player == 1)
								disp_die(p1_die);
							else
								disp_die(p2_die);

							disp_ask_reroll();
							scanf(" %c", &choice);
							if (choice == 'Y' || choice == 'y') //Player chooses to keep the roll and the game proceeds.
							{
								check = 1;
								roll = 4;
								system("cls");
							}
							else if (choice == 'N' || choice == 'n') //Player chooses to reroll their dice/die.
							{
								int num_reroll = 0, reroll_die = 0;
								printf("---------------------------------------\n");
								printf("| How many die do you want to reroll? |\n");
								printf("---------------------------------------\n");
								scanf("%d", &num_reroll);

								while (num_reroll < 1 || num_reroll > 6) //Checks for invalid input.
								{
									invld_inpt();
									printf("\n---------------------------------------\n");
									printf("| How many die do you want to reroll? |\n");
									printf("---------------------------------------\n");
									scanf("%d", &num_reroll);
								}

								if (player == 1) //Determines if it is currently player 1 or player 2's turn.
								{
									reroll(num_reroll, p1_die); //Rerolls the player's selected die.
									check = 1;
								}
								else
								{
									reroll(num_reroll, p2_die); //Rerolls the player's selected die.
									check = 1;
								}
							}
							else //Invalid input by player.
							{
								invld_inpt();
								disp_ask_reroll();
								scanf(" %c", &choice);
							}

						} while (check == 0);

					}

					system("cls");
					int combo_choice = 0;
					printf("--------------------------------------------------------\n");
					printf("| Which combination do you choose based on your rolls? |\n");
					printf("--------------------------------------------------------\n");
					disp_combos(); //Displays the list of 13 combos for the players to choose.
					if (player == 1) //Determines which player's dice array to access.
					{
						disp_die(p1_die); //Displays the player's die.
						disp_scores(1, p1_sec);
						scanf("%d", &combo_choice);
						while (combo_choice < 1 || combo_choice > 13) //Checks for invalid input, displays appropriate message, and asks for an input again.
						{
							system("cls"); //Clear's the screen.
							invld_inpt();
							disp_combos();
							disp_die(p1_die);
							disp_scores(1, p1_sec);
							scanf("%d", &combo_choice);
						}
						decide_combo(combo_choice, p1_die, p1_sec); //Asks the player for the combination based on their roll and stores the score into their score array.

					}
					else
					{
						disp_die(p2_die); //Displays the player's die.
						disp_scores(2, p2_sec);
						scanf("%d", &combo_choice);
						while (combo_choice < 1 || combo_choice > 13) //Checks for invalid input, displays appropriate message, and asks for an input again.
						{
							system("cls"); //Clear's the screen.
							invld_inpt();
							disp_combos();
							disp_die(p2_die);
							disp_scores(2, p2_sec);
							scanf("%d", &combo_choice);
						} 
						decide_combo(combo_choice, p2_die, p2_sec); //Asks the player for the combination based on their roll and stores the score into their score array.

					}

				}

				round++;
			} while (round < 14);

			tot_score1 = total_score(p1_sec); //Determines the total score for player 1.
			tot_score2 = total_score(p2_sec); //Determines the total score for player 2.
			tot_score1 = is_add_points(p1_sec, tot_score1); //Determines if the score of the upper section is greater than or equal to 63 for player 1's upper section.
			tot_score2 = is_add_points(p2_sec, tot_score2); //Determines if the score of the upper section is greater than or equal to 63 for player 2's upper section.

			//Determines which player wins (or a tie), displays appropriate message and asks if the players want to play again.
			if (tot_score1 > tot_score2) 
			{
				printf("------------------------------------------------\n");
				printf("| Congrats! Player 1, you win with %d points!! |\n", tot_score1);
				printf("------------------------------------------------\n");
				printf("---------------------------\n");
				printf("| Player 2 had %d points. |\n", tot_score2);
				printf("---------------------------\n");
				printf("--------------------------------\n");
				printf("| Press ENTER key to continue. |\n");
				printf("--------------------------------\n\n");
				getch();
				system("cls");
			}
			else if (tot_score1 < tot_score2)
			{
				printf("------------------------------------------------\n");
				printf("| Congrats! Player 2, you win with %d points!! |\n", tot_score2);
				printf("------------------------------------------------\n");
				printf("---------------------------\n");
				printf("| Player 1 had %d points. |\n", tot_score1);
				printf("---------------------------\n");
				printf("--------------------------------\n");
				printf("| Press ENTER key to continue. |\n");
				printf("--------------------------------\n\n");
				getch();
				system("cls");
			}
			else
			{
				printf("----------------------------------------------\n");
				printf("| Woah! It's a tie! you both have %d points! |\n", tot_score1);
				printf("----------------------------------------------\n");
				printf("--------------------------------\n");
				printf("| Press ENTER key to continue. |\n");
				printf("--------------------------------\n\n");
				getch();
				system("cls");
			}
			num = replay(); //Asks the players if they want to play again or not.
			while (num < 1 || num > 3) //Checks for invalid input.
			{
				num = replay();
			}
		}
		break;
		case 2: //Displays rules.
		{
			system("cls");
			disp_rules(); //Displays the rules.
			printf("--------------------------------\n");
			printf("| Press ENTER key to continue. |\n");
			printf("--------------------------------\n\n");
			getch();
		}
		break;
		case 3: //Exits the game.
		{
			num = 4;
		}
		break;
		}

	} while (num >= 1 && num < 3);

	system("cls");
	printf("\n--------------------------\n");
	printf("| Thank you for playing! |\n"); //Displays a goodbye message.
	printf("--------------------------\n");

	return 0;
}
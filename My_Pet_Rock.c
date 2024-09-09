//Remake of "my pet rock". The goal was to rework certain mechanics and overhaul the random generation to be more complex

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main_loop_functions.h"
#include "nonprimary_functions.h"
#include "rock_generator.h"


int main()
{
    srand(time(0));

    char ROCK_SEED[10][20];
    int stats[6];
    char name[25];

    char user_input[100]; //This is a lot but I have to allow extra space for monsters who would try and overload the system!
    int X_VALUE = 0;
    int Y_VALUE = 0;
    char line_break[10]; //exists soley as a blank input field for blank lines

    //Fills ROCK_SEED with blank values so it can print properly
    rock_seed_initializer(ROCK_SEED);
    //This whole section is dedicated to generating each wall of the rock (one wall at a time so it's easier to tweak values later)
    X_VALUE = randomize_up(ROCK_SEED, X_VALUE);
    Y_VALUE = randomize_right(ROCK_SEED, X_VALUE, Y_VALUE);
    if (Y_VALUE < 10)
    //a right wall is only generated if the top doesn't touch the floor
    {
        X_VALUE = 20;
        randomizedown(ROCK_SEED, Y_VALUE, X_VALUE);
    }
    randomize_left(ROCK_SEED);

    printf ("Welcome to \"My Pet Rock\"! The very best in rock simulation.\n\n");
    
    while(1)
    {
        printf ("Is this your first time in the simulation? If not you may load your game by typing in \"LOAD\". Otherwise, please type in \"NEW\": ");
        scanf ("%s", user_input);
        all_lowercase(user_input);

        if (strcmp(user_input, "new") == 0)
        {
            rock_print(ROCK_SEED);
            statsroller(stats);
            statsprinter(stats);
            
            while(1)
            {
                printf ("\n\nThis is the look and stats of your new rock. Do you accept?(Y/N): ");
                scanf("%s", user_input);
                all_lowercase(user_input);
                
                if (strcmp(user_input, "y") == 0)
                {
                    printf ("\nGood! We'll proceed with the game!");
                    break;
                }
                if (strcmp(user_input, "n") == 0)
                {
                    printf ("\nWell that's unfortunate. Now your rock knows you don't love it");
                    break;
                }
            }
            
        printf("\nWhat will you name your new compantion?: ");
        scanf ("%s", name);
        punpolice(name);
        break;
        }

        if (strcmp(user_input, "load") == 0)
        {
            load(ROCK_SEED, stats, name, user_input);
            break;
        }
    }

    //This is the main loop for the simulation
    while(1)
    {
        printf ("\n%s\n", name);
        rock_print(ROCK_SEED);
        printf (" ____________________________________________\n"
        "|Interact|Feed|View|Talk|Stats|Save|Load|Exit|\n"
        " --------------------------------------------\n");
        
        printf ("What will you do?: ");
        scanf("%s", user_input);
        all_lowercase(user_input);
        getchar();//gets rid of trailing \n so I can use fgets as a line break

        if (strcmp(user_input, "interact") == 0)
        {
            interact(name, line_break);
        }
        else if (strcmp(user_input, "feed") == 0)
        {
            feed(name, user_input, line_break);
        }
        else if (strcmp(user_input, "view") == 0)
        {
            printf ("That sure is a rock you got there...: ");
            fgets(line_break, 10, stdin);
        }
        else if (strcmp(user_input, "talk") == 0)
        {
            printf ("What would you like to say?: ");
            fgets(line_break, 100, stdin); //not user input because we're not saving the field
        }
        else if (strcmp(user_input, "stats") == 0)
        {
            statsprinter(stats);
            printf ("Press \"enter\" to leave. ");
            fgets(line_break, 5, stdin);
        }
        else if (strcmp(user_input, "save") == 0)
        {
            save(ROCK_SEED, stats, name, user_input);
        }
        else if (strcmp(user_input, "load") == 0)
        {
            load(ROCK_SEED, stats, name, user_input);
        }
        else if (strcmp(user_input, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            printf ("\nInvalid command. Please do better next time\n");
        }
        
    }


    return 0;
}
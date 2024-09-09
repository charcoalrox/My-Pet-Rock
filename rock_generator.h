//This header file houses the rock generator functions for "My Pet Rock"


int rock_seed_initializer(char ROCK_SEED[10][20])
{
    for (int i=0; i<10; i++)
    //I know this seems wasteful here but trust me, it has to run first. This is the only way
    {
        for (int j=0; j<20; j++)
        {
            ROCK_SEED[i][j] = ' ';
        }
    }

    return 0;
}


int randomize_up(char ROCK_SEED[10][20], int X_VALUE)
//creates the left wall of our rock. Stops two points from the top so we can have more variety with the top generation function
{
    char ROCK_SELECTOR;

    for (int y = 9; y > 0; y--)
    {
        switch (rand() %3)
        {
            case 0:
                ROCK_SELECTOR = '|';
                break;
            case 1:
                if (X_VALUE > 0 && y != 1) //stops the wall from printing off of the grid and stops the ugly corner generation this piece causes
                {
                    ROCK_SELECTOR = '\\';
                    X_VALUE --;
                }
                else
                {
                    ROCK_SELECTOR = '/';
                    X_VALUE ++;
                }
                
                break;
            case 2:
                ROCK_SELECTOR = '/';
                X_VALUE ++;
                break;
            default:
                ROCK_SELECTOR = '|';
                break;
        }

        ROCK_SEED[y][X_VALUE] = ROCK_SELECTOR;
    }
    return X_VALUE;
}


int randomize_right(char ROCK_SEED[10][20], int X_VALUE, int Y_VALUE) //generates the top of the rock
{
    int partpicker;
    char ROCK_SELECTOR;

    for (int x = X_VALUE + 1; x < 20; x++)
    {
        partpicker =  (rand() %4);
        if (partpicker <= 2)
        {
            ROCK_SELECTOR = '_';
        }
        else if (partpicker == 3)
        {
            Y_VALUE ++;
            ROCK_SELECTOR = '\\';
        }

        if (x == 19 && ROCK_SELECTOR != '\\')
        /*fixes ugly corner generation by making the last piece always slope down
        it makes sure it isn't itself so that "y_value ++" bit doesn't cause a giant space*/
        {
            Y_VALUE ++;
            ROCK_SELECTOR = '\\';
        }

        ROCK_SEED[Y_VALUE][x] = ROCK_SELECTOR;

        if (Y_VALUE == 10)
        //stops generating the top if we reach floor
        {
            break;
        }

        if (ROCK_SELECTOR == '/')
        //shifts the next piece or rock up so that it matches the point of these characters
        {
            Y_VALUE --;
        }
    }
    return Y_VALUE;
}


int randomizedown(char ROCK_SEED[10][20], int Y_VALUE, int X_VALUE)
{
    char ROCK_SELECTOR;
    X_VALUE = 19; //this is all the way right. 0-19

    for (int y=Y_VALUE+1; y<10; y++) //Y_VALUE+1 so we don't overwrite the last ceiling piece
    {
        switch (rand() %3)
        {
            case 0:

                ROCK_SELECTOR = '|';
                break;
            case 1:
                if (X_VALUE >= 18 || y >= Y_VALUE)
                {
                    ROCK_SELECTOR = '/';
                    X_VALUE --;
                }
                else
                {
                    ROCK_SELECTOR = '\\';
                    X_VALUE ++;
                }
                break;
            case 2:
                ROCK_SELECTOR = '/';
                X_VALUE --;
                break;
            default:
                ROCK_SELECTOR = '|';
                break;
        }

        ROCK_SEED[y][X_VALUE] = ROCK_SELECTOR;
    }
    return Y_VALUE;
}



int randomize_left(char ROCK_SEED[10][20])
{
    int wall_checker = 0;

    for (int i=0; i<20; i++)
    {
        //checks if we're between the lines of the bottom row (to generate the floor)
        if (wall_checker == 0 && (ROCK_SEED[9][i] == '|' || ROCK_SEED[9][i] == '/' || ROCK_SEED[9][i] == '\\'))//noting here that I've left out '_' since this was originally a shader. JIC it becomes important in legacy
        {
             wall_checker = 1;
        }
        else if (wall_checker == 1 && (ROCK_SEED[9][i] == '|' || ROCK_SEED[9][i] == '/' || ROCK_SEED[9][i] == '\\'))
        {
            wall_checker = 0;
        }

        //draws the floor
        if (wall_checker == 1 && (ROCK_SEED[9][i] != '|' && ROCK_SEED[9][i] != '/' && ROCK_SEED[9][i] != '\\'))
        {
            ROCK_SEED[9][i] = '_';
        }       
    }


    return 0;
}


int rock_print(char ROCK_SEED[10][20])
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<20; j++)
        {
            printf ("%c", ROCK_SEED[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
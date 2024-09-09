//All of the functions that directly interact with your pet rock (everything that specifically appears on the menu bar)


void interact(char name[25], char line_break[10])
{
    int event_picker = rand() % 10;

    switch (event_picker)
    {
        case 0:
            printf ("You roll %s down a pretty steep hill. They seem like they're having fun.", name);
            fgets (line_break, 10, stdin);
            break;
        case 1:
            printf ("You pick up a few more rocks and attempt to juggle. You fail but it was pretty fun.");
            fgets (line_break, 10, stdin);
            break;
        case 2:
            printf ("You take in the fresh, outdoor air with %s.", name);
            fgets (line_break, 10, stdin);
            break;
        case 3:
            printf ("You go for a pleasant walk with %s.", name);
            fgets (line_break, 10, stdin);
            break;
        case 4:
            printf ("You stumble and drop %s. Not a scratch on 'em. What. A. CHAMP!!!", name);
            fgets (line_break, 10, stdin);
            break;
        case 5:
            printf ("You smack %s as hard as you can. It makes that satisfying SMACK noise. NICE!", name);
            fgets (line_break, 10, stdin);
            break;
        case 6:
            printf ("You start rotating %s to see if they sit nicer on any other sides. It just looks incorrect though...", name);
            fgets (line_break, 10, stdin);
            break;
        case 7:
            printf ("You think about how lucky you are to have stumbled upon %s.", name);
            fgets (line_break, 10, stdin);
            break;
        case 8:
            printf ("You drop %s on your foot. After some time passes and the pain subsides you apologize for cursing so much.", name);
            fgets (line_break, 10, stdin);
            break;
        case 9:
            printf ("You wonder if it's racist to say %s's favorite music genre is rock and roll...", name);
            fgets (line_break, 10, stdin);
            break;
        default:
            printf ("You grab a knife and slit open the palm of your hand.\n"
            "Blood pours from your gash and onto your friend's stiff flesh.\n"
            "The ritual feels as though it works a bit more every time.\n"
            "Soon flesh will merge with stone and a new era will have dawned.\n"
            "The end is nigh...");
            fgets (line_break, 10, stdin);
            break;
    }
}


void feed(char name[25], char user_input[100], char line_break[10])
{
    printf ("\nWhat would you feed to %s?: ", name);
    scanf ("%s", user_input);
    getchar();

    printf ("you load %s onto a spoon and feed it to %s.(press \"enter\" to continue)", user_input, name);
    fgets (line_break, 10, stdin);
    printf ("%s makes contact with %s but goes no farther than surface level.", user_input, name);
    fgets (line_break, 10, stdin);
    printf ("Rocks can't eat");
    fgets (line_break, 10, stdin);
}


void statsprinter(int stats[6])
{
    printf ("\n    STATS\n"
"  ---------\n\n"
"Rock           =   Yes\n"
"Dirt           =   %02d\n"
"Gray           =   %02d\n"
"Hardness       =   %02d\n"
"Intelligence   =   %02d\n"
"Lumps          =   %02d\n"
"Beauty         =   10\n"
, stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);
}


void save(char ROCK_SEED[10][20], int stats[6], char name[25], char user_input[10])
{
    char file_name[14];
    char file_extension[] = ".roc";

    FILE*GameSave;

    printf ("Please do not include file extensions in your name. Files are not case sensitive and don't accept spaces\n");
    printf ("What would you like to name your file?(max 10 chars): ");
    scanf ("%10s", file_name);
    
    strncat(file_name, file_extension, sizeof(file_extension));
    
    GameSave = fopen(file_name, "r");

    //This loop checks if a file already exists and, if so, asks the user if they want to overwrite said file
    while(1)
    {
        if (GameSave != NULL)
        {
            printf ("\nWARNING: This file already exists. Are you sure you would like to overwrite it?(y/n): ");
            scanf ("%s", user_input);
            all_lowercase(user_input);
        }

        //This is for the above if statement. I left it outside since the other statement didn't work inside the loop
        if (strcmp(user_input, "n") == 0)
        {
            printf ("Action terminated. Returning to main simulation.\n\n");
            break;
        }

        else if (GameSave == NULL || (strcmp(user_input, "y") == 0))
        {
            GameSave = fopen(file_name, "w");

            fprintf (GameSave, "%s ", name);
            for (int i=0; i<=sizeof(stats); i++)
            {
                fprintf (GameSave, "%d,", stats[i]);
            }
            fprintf(GameSave, "%s", ROCK_SEED);


            printf ("Your file has been saved\n\n");
            break;
        }
    }
    
    fclose(GameSave);
}


void load(char ROCK_SEED[10][20], int stats[6], char name[25], char user_input[14])
{
    char file_extension[] = ".roc";

    FILE*GameLoad;

    printf ("\nFiles are not case sensitive. Also do not include the file extension!\n");
    printf ("Which file are you loading?: ");
    scanf ("%10s", user_input);
    
    strncat(user_input, file_extension, sizeof(file_extension));

    GameLoad = fopen(user_input, "r");

    if (GameLoad == NULL)
    {
        printf ("\nThe selected file is not available. Proccess aborted\n");
    }

    if (GameLoad != NULL)
    {
        fscanf (GameLoad, "%s ", name);
        for (int i=0; i<=sizeof(stats); i++)
        {
            fscanf (GameLoad, "%d,", &stats[i]);
        }
        fgets(ROCK_SEED, 200, GameLoad); //must be fgets because scanf ignores whitespace
    }

    fclose(GameLoad);
}
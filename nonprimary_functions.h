//Setup for My Pet Rock. The things not used for the main game loop or rock generation

void statsroller(int stats[6])
{
    for (int i=0; i<6; i++)
    {
            stats[i] = rand() %11;
    }
}


void all_lowercase(char user_input[9])
{
    //case sensetivity in c!!!
    for (int i=0; i<11; i++)
    {
        if (user_input[i] >= 'A' && user_input[i] <= 'Z')
        {
            user_input[i]+=32;
        }
    }
}


void punpolice(char name[30])
{
    char rock_lower[] = "rock";
    char rock_upper[] = "ROCK"; //When I made this I think my class was saying nested functions were frowned upon hence not just using all_lowercase here
    char NEW_NAME[] = "[CENSORED]";

    for (int i = 0; i<30; i++) //"i" saves the position of our user's name
    {

        for (int j=0; j<5; j++) //"j" saves the position of the word rock so we can hunt for puns
        {
            if ((name[i] == rock_lower[j] || name[i] == rock_upper[j]) && (j < 4))
            {
                i++;
            }
            else if (j == 4)
            {
                printf ("\nLOW EFFORT ROCK PUNS ARE BANNED!!!\n");
                
                for (int k = 0; k<30; k++) //"K" is used to update our array since you can't easily export arrays from functions
                {
                    name[k] = NEW_NAME[k];
                    if (k>11)
                    {
                        name[k] =  ' ';
                    }
                }
                break;
            }
            else
            {
                break;
            }
            
        }
    }
}
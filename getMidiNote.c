#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum note{C, Cb, D, Db, E, F, Fb, G, Gb, A, Ab, B};
const char* notes[] = {"C", "Cb", "D", "Db", "E", "F", "Fb", "G", "Gb", "A", "Ab", "B"};

int getMidiNote()
{
    char noteInput[4];
    char noteOnly[3];
    scanf("%s", noteInput);
    if (isdigit(noteInput[1]))
    {
        noteOnly[0] = noteInput[0];
        noteOnly[1] = '\0';
    }
    else if (noteInput[1] == 'b')
    {
        noteOnly[0] = noteInput[0];
        noteOnly[1] = noteInput[1];
        noteOnly[2] = '\0';
    }
    else
    {
        printf("Invalid Input\n");
    }

    printf("%s\n", noteOnly);

    for (size_t i = 0; i < 12; i++)
    {
        if (!strcmp(notes[i], noteOnly))
        {
            printf("This is note numer %d\n", (int)i);
        }        
    }
    
    return 0;
}

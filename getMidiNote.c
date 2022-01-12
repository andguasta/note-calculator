#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char* notes[] = {"C", "Cb", "D", "Db", "E", "F", "Fb", "G", "Gb", "A", "Ab", "B"};

int getMidiNote(char* noteInput)
{
    
    int octave;
    int noteNumber;
    char noteOnly[3];
    int noteMidi;
    
    if (isdigit(noteInput[1]))
    {
        noteOnly[0] = noteInput[0];
        noteOnly[1] = '\0';
        octave = (int)noteInput[1] - 48;
    }
    else if (noteInput[1] == 'b')
    {
        noteOnly[0] = noteInput[0];
        noteOnly[1] = noteInput[1];
        noteOnly[2] = '\0';
        octave = (int)noteInput[2] - 48;
    }
    else
    {
        printf("Invalid Input\n");
    }

    //printf("%s\n", noteOnly);
    //printf("%d\n", octave);

    octave += 1; //Fix for correct range
    
    for (size_t i = 0; i < 12; i++)
    {
        if (!strcmp(notes[i], noteOnly))
        {
            noteNumber = i;
            //printf("This is note numer %d\n", (int)i);
            break;
        }        
    }

    noteMidi = octave*12+noteNumber;
    //printf("Note Midi: %d\n", noteMidi);

    return noteMidi;
}

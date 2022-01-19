#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include <math.h>
#include "conversions.h"

#define NUM_MODES 2
 
int main(int argc, char const *argv[])
{
    double baseFreq = 440;
    double noteFrequency;
    int semiFromA4;
    int mode = 0;
    char* userInput;
    
    char noteInput[4];

    if (argc == 1) // Prompt User
    {
        userInput = malloc(sizeof(char)*100);
        while(1)
        {
            printf("1 to input note name; 2 to input frequency\n");
            scanf("%s", userInput);
            if (strlen(userInput) > 1)
            {
                printf("Invalid input\n");
            }
            else
            {
                mode = (int)(userInput[0]-'0');
                if (mode == 0 || mode > NUM_MODES)
                {
                    printf("Invalid mode number\n");
                }
                else
                {
                    break;
                }                        
            }
        }        
        if (mode == 1)
        {
            while(1)
            {
                printf("Enter Note plus octave Ex. C4 or Eb3: ");
                scanf("%s", userInput);
                if (strlen(userInput) > 3)
                {
                    printf("Please enter a valid note Ex. C4 or Eb3:\n");
                }
                else
                {
                    strncpy(noteInput, userInput, 4);
                    int midiNote = string2midi(noteInput);
                    if (midiNote == -1)
                    {
                        printf("The note is in an invalid format\n");
                    }
                    else
                    {
                        break;
                    }                        
                }        
            }
            noteFrequency = midi2Freq(string2midi(noteInput));
            printf("The Note Frequency is %0.2fhz\n", noteFrequency);
            printf("The Note Midi Number is: %d\n", string2midi(noteInput));
        }
        else if (mode == 2)
        {
            double userFrequency;
            while(1)
            {
                //short validity = 0;
                printf("Enter a frequency Ex 350:\n");
                scanf("%s", userInput);
                char* garbageInput;
                userFrequency = strtod(userInput, &garbageInput);
                if (userFrequency > 0.0f)
                {
                    break;
                }
                else
                {
                    printf("Please enter a valid Input\n");
                }         
            }
            // double userFrequency = atoi(userInput);
            int noteNumber = -1;
            noteNumber = freq2Midi(userFrequency);
            printf("The Note Midi Number is: %d\n", noteNumber);
            char noteName[4];
            midi2String(noteNumber, noteName);
            printf("The Note Name is: %s\n", noteName);
        }
        free(userInput);
    }
    else
    {
        char* tempPoint; 
        if (strncmp(argv[1],"-m", 2) == 0)
        {            
            short midiNum;
            midiNum = (short)strtod(argv[2], &tempPoint);
            printf("Midi Note %d -> Freq: %0.2fhz\n", midiNum, midi2Freq(midiNum));
        }
        else if (strncmp(argv[1],"-f", 2) == 0)
        {         
            double frequency;
            frequency = (short)strtod(argv[2], &tempPoint);
            printf("Freq: %0.2fhz -> Midi Note %d\n", frequency, freq2Midi(frequency));
        }
        else if (strncmp(argv[1],"-s", 2) == 0)
        {
            strncpy(noteInput, argv[2], 3);
            noteInput[3] = '\0';            
            printf("Note %s -> Midi Note %d -> Freq: %0.2fhz\n", noteInput, string2midi(noteInput), midi2Freq(string2midi(noteInput)));
        }
        else if(strncmp(argv[1],"-7", 2) == 0)
        {
            //Using this only for testing
        }
        else
        {
            printf("Argument non valid\n");
        }
        
    }
      
    return 0;
}

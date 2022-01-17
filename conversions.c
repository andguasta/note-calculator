#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define A4_MIDI_NUM 69

int tuning = 440;

const char* notes[] = {"C", "Cb", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};

int string2midi(char* noteInput)
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

    octave += 1; //Fix for correct range
    
    for (size_t i = 0; i < 12; i++)
    {
        if (!strcmp(notes[i], noteOnly))
        {
            noteNumber = i;
            break;
        }
        if (i == 11)
        {
            return -1;
        }             
    }

    noteMidi = octave*12+noteNumber;
    return noteMidi;
}

void midi2String(int noteNumber, char* noteName)
{
    strncpy(noteName, notes[noteNumber%12], strlen(notes[noteNumber%12]));
    int octave = (noteNumber / 12) - 1;
    noteName[strlen(notes[noteNumber%12])] = (char)('0'+octave);
    noteName[strlen(notes[noteNumber%12]) + 1 ] = '\0';
}

double midi2Freq(int note)
{
    int semiFromA4 = note - string2midi("A4");
    double frequency = tuning * pow(2, (float)semiFromA4/12.f);
    return frequency;
}

int freq2Midi(double frequency)
{
    float semiFromA;
    semiFromA = 12*log2(frequency/tuning);
    int noteNumber = A4_MIDI_NUM + (int)round(semiFromA);
    return noteNumber;
}


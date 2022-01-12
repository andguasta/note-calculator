#include <stdio.h>
#include <math.h>
int getMidiNote();

int main()
{
    double baseFreq = 440;
    double noteFrequency;
    int semitFromA4;
    
    char noteInput[4];
    printf("Enter Note plus octave Ex. C4 or Eb3: ");
    scanf("%s", noteInput);
    
    semitFromA4 = getMidiNote(&noteInput) - getMidiNote("A4");
    //printf("Diff is %d\n", semitFromA4);

    noteFrequency = baseFreq * pow(2, (float)semitFromA4/12.f);
    printf("The note Frequency is %f\n", noteFrequency);

    return 0;
}

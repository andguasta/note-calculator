#include <stdio.h>
#include <math.h>
int getMidiNote();

int main()
{
    // const char* noteNames[] = {"C", "Cb", "D", "Db", "E", "F", "Fb", "G", "Gb", "A", "Ab", "B"};

    // double calc = 1;
    // double baseFreq = 440;
    // double calculatedFreq1 = 0;
    // double calculatedFreq2 = 0;
    // for (int i = 0; i < 24; i++)
    // {
    //     calculatedFreq1 = baseFreq * pow(2, (float)i/12.f);
    //     printf("note %s is : %f\n", noteNames[(i+9)%12], calculatedFreq1);
    //     printf("--------------\n");
    // }
    getMidiNote();
    
    return 0;
}

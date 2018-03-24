// Helper functions for music application
//Functions are used to read a text file, interpret it, and return notes and frequencies to be made into WAV file

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[0] == '1')
    {
        if (fraction[2] == '1')
            return 8;
        else if (fraction[2] == '2')
            return 4;
        else if (fraction[2] == '4')
            return 2;
        else if (fraction[2] == '8')
            return 1;
    }
    else if (fraction[0] == '3' && fraction[2] == '8')
        return 3;
    else
        return 0;
    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //find the octave and convert the ASCII value to a float
    float octave = note[strlen(note) - 1];
    octave -= 48.0;
    //A4 = 440, A3 = 220, A6 = 1760
    //A5 = 440 * 2, A6 = 440 * (2^octave-4)

    char notel = note[0]; //noteletter
    //n will be what I use to push the frequency forward or back from its A4 base of 440Hz
    int n;

    if (notel == 'A')
        n = 0.0;
    else if (notel == 'B')
        n = 2.0;
    else if (notel == 'C')
        n = -9.0;
    else if (notel == 'G')
        n = -2.0;
    else if (notel == 'F')
        n = -4.0;
    else if (notel == 'E')
        n = -5.0;
    else if (notel == 'D')
        n = -7.0;
    else
        return 1;
    //calculate the accidentals
    if (note[1] == 'b')
        n--;
    else if (note[1] == '#')
        n++;

    //2 ^ (1/12)
    float temp = (n / 12.0);
    float freq = powf(2.0, temp) * 440.0;
    //for every octave, multiply or divide the frequency by two
    freq *= powf(2.0, (octave - 4));
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strncmp(s, "", 1))
        return false;
    else
        return true;
}

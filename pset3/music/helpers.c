// Helper functions for music
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

// A4 is global Variable - 440.0 hz

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    if (fraction[0] == '1')
    {

        if (fraction[2] == '8')
        {
            return 1;
        }
        else if (fraction[2] == '4')
        {
            return 2;
        }
        else if (fraction[2] == '2')
        {
            return 4;
        }
        else if (fraction[2] == '1')
        {
            return 8;
        }
    }
    else if (fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }

    return 0;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    // 1. Parsing the string into Octave and note
    int octave = note[strlen(note) - 1];

    // 2. ASCII into int value
    // Octave has int value of (Whatever Number user enters)
    // 'Octave' - '0' it evaluates to Octave - 48 or int Octave
    octave -= 48;

    // 3. Determining Frequency
    double freq = 0.0;

    // 4. Determing Note Letter
    switch (note[0])
    {

    case 'C':
        freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
        break;

    case 'D':
        freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
        break;

    case 'E':
        freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
        break;

    case 'F':
        freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
        break;

    case 'G':
        freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
        break;

    case 'A':
        freq = 440.0;
        break;

    case 'B':
        freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
        break;

    default:
        return 0;
    }

    // 5. Shift to Octave
    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // 6. Adjustment for flat or sharp
    if (note[1] == 'b')
    {
        freq /= pow(2.0, (1.0 / 12.0));
    }
    else if (note[1] == '#')
    {
        freq *= pow(2.0, (1.0 / 12.0));
    }

    // 7. Return frequency value as int
    int freqReturn = round(freq);
    return freqReturn;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO

    if (strncmp(s, "", 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}

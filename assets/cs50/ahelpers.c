// Helper functions for music

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    string numerator = strtok(fraction, "/");
    string denominator = strtok(NULL, "/");
    int n = atoi(numerator);
    int d = atoi(denominator);
    int eighths = n;

    if (d == 4)
    {
        eighths *= 2;
    }
    if (d == 2)
    {
        eighths *= 4;
    }
    if (d == 1)
    {
        eighths *= 8;
    }
    return eighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //string note = argv[1];
    //digesting input
    char letter = toupper(note[0]);
    int accent = 0;
    int octave;
    //if accidental present then modify letter result and note[2] = octave
    if (note[1] == 'b')
    {
        accent = -1;
        octave = note[2] - 48;
    }
    else if (note[1] == '#')
    {
        accent = 1;
        octave = note[2] - 48;
    }
    //else note[1] is the octave
    else
    {
        octave = note[1] - 48;
    }

    int semitone = 0;
    switch (letter)
    {
        case 'C':
            semitone = 0;
            break;
        case 'D':
            semitone = 2;
            break;
        case 'E':
            semitone = 4;
            break;
        case 'F':
            semitone = 5;
            break;
        case 'G':
            semitone = 7;
            break;
        case 'A':
            semitone = 9;
            break;
        case 'B':
            semitone = 11;
            break;
        default:
            semitone = 9;
            break;
    }
    int tone = semitone + accent;

    float tonedif = tone - 9;

    float octdif = octave - 4;


    double hz = pow(2, (tonedif + (octdif * 12)) / 12) * 440;
    int hertz = round(hz);
    return hertz;

    //mathing digested input
    //2^(n/12) X 440 where n is the number of semitones from that note to A4 (0 index 9th tone of 4th octave)
    //440Hz == A4
    //to change the octave multiply or divide by some power of 2
    //round decimals
    //to make sharp multiple Hz by 2^(1/12)
    //to make flat divide Hz by 2^(1/12)
    //Support A# and Ab
    //A as starting point
    //Octaves start at C

    //returning output
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp("", s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

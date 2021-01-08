#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

typedef struct
{
    char *key;
    int step;
} freq;

/*duration, which should take as input as a string a fraction (e.g., 1/4)
and return as an int a corresponding number of eigths (2, in this case, since 1/4 is equivalent to 2/8)*/

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    double d, n ;
    float f_eighths = 0;

    // Parse the fraction.
    string numerator = strtok(fraction, "/");
    // In the next call to strtok, the first parameter needs to be NULL so that strtok starts
    // splitting the string from the next token's starting position it remembers.
    string denominator = strtok(NULL, "/");

    //Convert numerator to double to check for whole notes.
    sscanf(numerator, "%lf", &n);
    if (n >= 1 && denominator == NULL)
    {
        f_eighths = n;
    }
    else
    {
        // Convert string to double.
        sscanf(numerator, "%lf", &n);
        sscanf(denominator, "%lf", &d);
        f_eighths = n / d;
    }
    //Divide to see how many eighths are in the note.
    f_eighths /= .125;
    //Convert float to int.
    int eighths = (int) f_eighths;
    //printf("%d", eighths);

    return eighths;
}


/*frequency, which should take as input as a string a note formatted as
XY (e.g., A4), where X is any of A through G and Y is any of 0 through 8, or
XYZ (e.g., A#4), where X is any of A through G, Y is # or b, and Z is any of 0 through 8,
and return as an int the note’s corresponding frequency, rounded to the nearest integer; and
*/

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

    if (note == NULL)
    {
        return 1;
    }
// Struct for how many semitones away note is within the octave.
    freq s_tone[] = {{"C", -9}, {"C#", -8}, {"Db", -8}, {"D", -7}, {"D#", -6},
        {"Eb", -6}, {"E", -5}, {"F", -4}, {"F#", -3}, {"Gb", -3},
        {"G", -2}, {"G#", -1}, {"Ab", -1}, {"A", 0}, {"A#", 1},
        {"Bb", 1}, {"B", 2}

    };

    char *find = NULL;
    char *tmp;
    char octave[2];
    int i_step = 0;
    int i_tmp = 0;
    float f = 0;

    //There's a better way to do this.
    find = strchr(note, '#');
    if (find == NULL)
    {
        find = strchr(note, 'b');
    }

    //allocate memory for new string.
    tmp = (char *) malloc(sizeof(note + 1));
    // make a copy of note to work with.
    strcpy(tmp, note);

    //Check to see the if the note is sharp or flat.
    if (find)
    {
        strcpy(octave, tmp + 2);
        // parse tmp, get the note by itself.
        tmp = strtok(tmp, octave);
    }
    else
    {
        strcpy(octave, tmp + 1);
        // parse tmp, get the note by itself.
        tmp = strtok(tmp, octave);
    }
    // iterate through the struct, find a match and get the semitones steps away
    // for A.
    for (int i = 0; s_tone[i].key ; i++)
    {
        // Found a match, assign the integer value for steps away from A.
        if (strcmp(tmp, s_tone[i].key) == 0)
        {
            i_step = s_tone[i].step;
            //printf("%s %d \n", s_tone[i].key, s_tone[i].step);
            break;
        }
        //Print out error message, free up memory allocated and leave.
        else if (i == 16 && (strcmp(tmp, s_tone[i].key) != 0))
        {
            printf("Invalid format, no match found. \n");
            free(tmp);
            exit(1);
        }
    }

    // Set i_tmp to the total semitones away from A4 based on octaves only.
    i_tmp = (atoi(octave) - 4) * 12;

    // Now add in how many steps away within the octave.
    i_tmp += i_step;

    // set f to the floating point version for maths and precision.
    f = (float) i_tmp;

    // Perform exponentials and round off to nearest whole number.
    // f = (2 ^ (n/12) * 440))
    f = roundf(powf(2.000, f / 12.000) * 440);

    // Convert f to float and store in i_tmp.
    i_tmp = (int) f;

    //No mermory leaks.
    free(tmp);
    return i_tmp;
}

/*
  is_rest, which should return true if its input,
  a string, represents a rest in our machine-readable format, otherwise false.
*/
// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

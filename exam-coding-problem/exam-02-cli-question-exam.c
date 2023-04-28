/*
Write a program in this file which counts the number of letters, digits,
and "other" characters (everything else) from the input.

String input(s) will be sent to the program via command line arguments. If no 
strings have been provided as input, the program should quit with the code 1 and 
tell the user that:

"<program name>: Error, missing string input"

Note that program name must be dynamically determined.

For full credit you must use ONE function in your solution to check each string
and return the counts for each character type (letters, digits, other).

Your function will have a void return type, may ONLY take pointers as 
parameters, and can ONLY take TWO parameters.

In the program examples below note that the $ just indicates that this is the
command being used to run your program. This is NOT a part of any of the counts
or output.

Example behavior:
$ ./count_types "3, 2, 1, blastoff"
8 letters
3 digits
6 other characters

Note that due to spaces, the command line argument is in quotation marks in the
example above so that it is considered a single argument. The quotation marks
are not part of the argument itself.

$ ./count_char_types
./count_char: Error, missing string input

Your grade for this program will be calculated as follows:
2 point  - the program style conforms to the class style guide and class
            examples
2 points - the program has the correct behavior as described above when
            counting characters from a command line argument(s)
2 point  - the program exits with an error message when the user does not
            provide input strings
4 point  - the program uses a function to count the character types from the
            command line input and meets the requirements above
*/

// Provide Includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// integers will be acceptable too
// total could be stored here as well
struct count {
    size_t letters;
    size_t numbers;
    size_t other;
};

void check_string(const char *string, struct count *ptr_count);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Missing string input!\n");
        exit(1);
    }

    struct count string_count = {0, 0, 0};

    for (int i = 1; i < argc; ++i) {
        check_string(argv[i], &string_count);
    }

    printf("letters: %zu\n", string_count.letters);
    printf("numbers: %zu\n", string_count.numbers);
    printf("other: %zu\n", string_count.other);
    
    return 0;
}

void check_string(const char *string, struct count *ptr_count) {
    size_t length = strlen(string);
    for (int i = 0; i < length; ++i) {
        if (isalpha(string[i])) {
            ptr_count->letters++;
        }
        else if (isdigit(string[i])){
            ptr_count->numbers++;
        }
        else {
            ptr_count->other++;
        }
    }
}

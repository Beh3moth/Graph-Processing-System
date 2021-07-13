#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

/**
 * The function returns the comma position starting from zero.
 * @param input is a
 * @return
 */
long int findSpacePosition(const char *input){
    long int i = 0;
    while(input[i] != ' '){
        i++;
    }
    return i;
}

/**
 * The method takes a line containing two numbers and puts the values in nodesNumber and in rankingLength.
 * @param input is the input's first line.
 * @param nodesNumber is the number of nodes (long int).
 * @param rankingLength is the length of the rank (long int).
 */
void takeFirstLine(char * input, long int * nodesNumber, long int * rankingLength){

    long int spacePosition = findSpacePosition(input);

    //Copy the first number
    long int *d = malloc(sizeof(long int));
    memcpy(d, input, spacePosition * sizeof(char));

    //Copy the second number
    long int *k = malloc(sizeof(long int));
    memcpy(k, input+spacePosition+1, sizeof(long int));

    *nodesNumber = (long int) d;
    *rankingLength = (long int) k;

}

#endif //UNTITLED_LIBRARY_H

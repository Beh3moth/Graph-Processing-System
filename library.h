#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

//TEXT MANAGEMENT METHODS

/**
 * The function returns the comma position starting from zero.
 * @param input is a buffer of text. The first char can't be a comma.
 * @return an integer of the position of the first space.
 */
long int findCommaPosition(const char *input){
    long int i = 0;
    while(input[i] != ','){
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
void takeFirstLine(char * input, long int * nodesNumber, long int * rankingLength) {
    char * endPtr;
    *nodesNumber = strtol(input, &endPtr, 10);
    *rankingLength = strtol(endPtr, &endPtr, 10);
}

long int takeNumber(char * line, long int i){
    long int commaPosition  = findCommaPosition(line + i);
    long int * number = malloc(sizeof(long int));
    memcpy(number, line+i, (unsigned long) (line + i - commaPosition * sizeof(char)));
    return (long int) number;
}

//MATRIX MANAGEMENT METHODS

void fillAdjacencyMatrix(long int * adjacencyMatrix, long int nodesNumber, char * line){
    for(int i=0; i<nodesNumber; i++){
        for(int j=0; j<nodesNumber; j++){
            *(adjacencyMatrix + j) = takeNumber(line, j);
        }
    }
}

#endif //UNTITLED_LIBRARY_H

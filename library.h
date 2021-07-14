#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

//TEXT MANAGEMENT METHODS

/**
 * The method takes a line containing two numbers and puts the values in nodesNumber and in rankingLength.
 * @param input is the input's first line.
 * @param nodesNumber is the number of nodes (long long int).
 * @param rankingLength is the length of the rank (long long int).
 */
void takeFirstTwoNumbers(char * input, long long int * nodesNumber, long long int * rankingLength) {
    char * endPtr;
    *nodesNumber = strtol(input, &endPtr, 10);
    *rankingLength = strtol(endPtr, &endPtr, 10);
}

long long int takeNumber(char * line){
    if(*line == ','){
        line++;
    }
    long long int number = strtol(line, &line, 10);
    return number;
}

//MATRIX MANAGEMENT METHODS

void fillAdjacencyMatrix(long long int * adjacencyMatrix, long long int nodesNumber, char * line){
    for(int j=0; j<nodesNumber; j++){
        *(adjacencyMatrix + j) = takeNumber(line);
    }
}

#endif //UNTITLED_LIBRARY_H

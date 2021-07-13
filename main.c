#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "library.h"

#define INPUT_SIZE 100

int main(int argc, char *argv[]) {

    //Take the first line
    char *input;
    input = malloc(INPUT_SIZE * sizeof(char));
    fgets(input, INPUT_SIZE, stdin);

    long int nodesNumber = 0;
    long int rankingLength = 0;

    takeFirstLine(input, &nodesNumber, &rankingLength);

    fputs((const char *) nodesNumber, stdout);
    fputs("\n", stdout);
    fputs((const char *) rankingLength, stdout);

    while(1){
        fgets(input, INPUT_SIZE, stdin);
        if(strcmp(input, "TopK") == 0){
            //return the result
            break;
        }
        else {
            //read the entire graph's adjacency matrix and execute the algorithm.
        }
    }

    fgets(input, INPUT_SIZE, stdin);

    return 0;

}


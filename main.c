#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "library.h"

#define MAX_FIRST_INPUT_SIZE 21
#define MAX_COMMAND_INPUT_SIZE 16
#define MAX_GRAPH_SIZE 1024

int main(int argc, char *argv[]) {

    //Take the first line
    char *firstInput;
    firstInput = malloc(MAX_FIRST_INPUT_SIZE * sizeof(char));
    fgets(firstInput, MAX_FIRST_INPUT_SIZE, stdin);

    long int nodesNumber = 0;
    long int rankingLength = 0;

    takeFirstLine(firstInput, &nodesNumber, &rankingLength);

    fputs((const char *) nodesNumber, stdout);
    fputs("\n", stdout);
    fputs((const char *) rankingLength, stdout);

    char *commandInput = malloc( MAX_COMMAND_INPUT_SIZE * sizeof(char) );
    char *graphInput = malloc( MAX_GRAPH_SIZE * sizeof(char) );

    while(1){
        fgets(commandInput, MAX_COMMAND_INPUT_SIZE, stdin);
        if(strcmp(commandInput, "TopK\r\n") == 0){
            //return the result
            break;
        }
        else if(strcmp(commandInput, "AggiungiGrafo\r\n") == 0) {
            fputs("AggiungiGrafo\n", stdout);
            fgets(graphInput, MAX_GRAPH_SIZE, stdin);
        }
    }

    return 0;

}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "library.h"

#define MAX_FIRST_INPUT_SIZE 21
#define MAX_COMMAND_INPUT_SIZE 16
#define MAX_GRAPH_SIZE 1024

int main(int argc, char *argv[]) {

    //Variables
    char *firstInput = malloc(MAX_FIRST_INPUT_SIZE * sizeof(char));
    char *commandInput = malloc( MAX_COMMAND_INPUT_SIZE * sizeof(char) );
    char *graphInput = malloc( MAX_GRAPH_SIZE * sizeof(char) );
    long int nodesNumber = 0;
    long int rankingLength = 0;

    //Take the first line
    fgets(firstInput, MAX_FIRST_INPUT_SIZE, stdin);
    takeFirstLine(firstInput, &nodesNumber, &rankingLength);

    //Print d and k
    printf("%ld", nodesNumber);
    printf("%c", ' ');
    printf("%ld", rankingLength);
    printf("%s", "\n");


    //Initialization of the adjacency Matrix
    long int adjacencyMatrix[nodesNumber][nodesNumber];

    //Command's cycle
    while(1){
        fgets(commandInput, MAX_COMMAND_INPUT_SIZE, stdin);
        if(strcmp(commandInput, "TopK\r\n") == 0){
            //return the result
            break;
        }
        else if(strcmp(commandInput, "AggiungiGrafo\r\n") == 0) {
            fputs("AggiungiGrafo\n", stdout);
            fgets(graphInput, MAX_GRAPH_SIZE, stdin);
            for(int i=0; i<nodesNumber; i++){
                //fillAdjacencyMatrix(&adjacencyMatrix[i][0], nodesNumber, graphInput);
            }
        }
    }

    return 0;

}


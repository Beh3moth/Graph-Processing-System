#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "library.h"

int main(int argc, char *argv[]) {

    //Variables
    char *input = NULL;
    long int nodesNumber = 0;
    long int rankingLength = 0;
    size_t len = 0;
    ssize_t lineSize = 0;

    lineSize = getline(&input, &len, stdin);

    takeFirstTwoNumbers(input, &nodesNumber, &rankingLength);

    //Print d and k
    printf("%ld", nodesNumber);
    printf("%c", ' ');
    printf("%ld", rankingLength);
    printf("%s", "\n");

    //Initialization of the adjacency Matrix
    long int adjacencyMatrix[nodesNumber][nodesNumber];

    //Command's cycle
    while(1){
        lineSize = getline(&input, &len, stdin);
        if(strcmp(input, "TopK\r\n") == 0){
            //return the result
            break;
        }
        else if(strcmp(input, "AggiungiGrafo\r\n") == 0) {
            fputs("AggiungiGrafo\n", stdout);
            lineSize = getline(&input, &len, stdin);
            for(int i=0; i<nodesNumber; i++){
                //fillAdjacencyMatrix(&adjacencyMatrix[i][0], nodesNumber, graphInput);
            }
        }
    }

    return 0;

}


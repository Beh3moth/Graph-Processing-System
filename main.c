#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "library.h"



int main(int argc, char *argv[]) {

    //Variables
    char *input = NULL;
    long long int nodesNumber = 0;
    long long int rankingLength = 0;
    size_t len = 0;
    node_t *head = NULL;
    long long int graphIndex = 0;


    if(getline(&input, &len, stdin)<=0){
        fputs("GetLine ERROR!", stdout);
    }

    takeFirstTwoNumbers(input, &nodesNumber, &rankingLength);

    //Instantiation of the adjacency Matrix
    long long int adjacencyMatrix[nodesNumber][nodesNumber];

    //Command's cycle
    while( getline(&input, &len, stdin)!=-1 ){

        if(strcmp(input, "TopK\r\n") == 0 || strcmp(input, "TopK\r") == 0 || strcmp(input, "TopK") == 0 || strcmp(input, "TopK\n") == 0){

            print_list(head, rankingLength);

        }
        else if(strcmp(input, "AggiungiGrafo\r\n") == 0 || strcmp(input, "AggiungiGrafo\n") == 0){

            //Fill the adjacencyMatrix
            for(int i=0; i<nodesNumber; i++){
                //The following line is just for debugging
                if(getline(&input, &len, stdin)==-1){
                    printf("%s", "getLine failure");
                }
                fillAdjacencyMatrix(&adjacencyMatrix[i][0], nodesNumber, input);
            }
            head = insertNode(head, dijkstra(nodesNumber, adjacencyMatrix), graphIndex, rankingLength);
            graphIndex++;

        }

    }

    return 0;

}


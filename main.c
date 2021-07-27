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

    //ssize_t lineSize = 0;

    getline(&input, &len, stdin);

    takeFirstTwoNumbers(input, &nodesNumber, &rankingLength);

    //Print d and k
    printf("%lld", nodesNumber);
    printf("%c", ' ');
    printf("%lld", rankingLength);
    printf("%s", "\n");

    //Initialization of the adjacency Matrix
    long long int adjacencyMatrix[nodesNumber][nodesNumber];
    long long int graphIndex = 0;

    //Command's cycle
    while(1){

        getline(&input, &len, stdin);
        if(strcmp(input, "TopK\r\n") == 0){
            fputs("TopK: ", stdout);
            print_list(head, rankingLength);
            break;
        }
        else if(strcmp(input, "AggiungiGrafo\r\n") == 0) {

            fputs("AggiungiGrafo\n", stdout);

            //Fill the adjacencyMatrix
            for(int i=0; i<nodesNumber; i++){
                //The following line is just for debugging
                if(getline(&input, &len, stdin)==-1){
                    printf("%s", "getLine failure");
                }
                fillAdjacencyMatrix(&adjacencyMatrix[i][0], nodesNumber, input);
            }

            //Print the adjacencyMatrix
            for(int k=0; k<nodesNumber; k++){
                for(int p=0; p<nodesNumber; p++){
                    printf("%lld", adjacencyMatrix[k][p]);
                    printf("%c", ',');
                }
                printf("%s", "\n");
            }

            head = insertNode(head, dijkstra(nodesNumber, adjacencyMatrix), graphIndex, rankingLength);
            graphIndex++;

        }

    }

    return 0;

}


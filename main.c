#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "library.h"

int main(int argc, char *argv[]) {

    //Variables
    char *input = NULL;
    long long int nodesNumber = 0;
    long long int rankingLength = 0;
    size_t len = 0;
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

    //Command's cycle
    while(1){

        getline(&input, &len, stdin);
        if(strcmp(input, "TopK\r\n") == 0){
            //return the result
            break;
        }
        else if(strcmp(input, "AggiungiGrafo\r\n") == 0) {
            fputs("AggiungiGrafo\n", stdout);

            for(int i=0; i<nodesNumber; i++){
                if(getline(&input, &len, stdin)==-1){
                    printf("%s", "getLine failure");
                }
                fillAdjacencyMatrix(&adjacencyMatrix[i][0], nodesNumber, input);
            }


            for(int k=0; k<nodesNumber; k++){
                for(int p=0; p<nodesNumber; p++){
                    printf("%lld", adjacencyMatrix[k][p]);
                    printf("%c", ',');
                }
                printf("%s", "\n");
            }

        }
    }

    return 0;

}


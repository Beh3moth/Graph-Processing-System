#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "library.h"

typedef struct node {
    long long int graphIndex;
    long long int sumValue;
    struct node * next;
} node_t;

void print_list(node_t * head, long long int rankingLength) {
    node_t * current = head;
    long long int counter = 0;
    while (current != NULL && counter<rankingLength) {
        printf("%lld ", current->graphIndex);
        current = current->next;
        counter++;
    }
}

node_t* insertNode(node_t * head, long long int sumValue, long long int graphIndex, long long int rankingLength){

    node_t *newNode, *prevNode, *nextNode;
    node_t *headBackup;

    newNode = (node_t *) malloc(sizeof(node_t));
    newNode->graphIndex = graphIndex;
    newNode->sumValue = sumValue;
    newNode->next = NULL;

    //Insert in head
    if((head) == NULL){
        (head) = newNode;
    }
    else {

        nextNode = (head);
        prevNode = NULL;
        headBackup = (head);

        long long int counter = 0;
        while(nextNode != NULL && sumValue >= nextNode->sumValue && counter < rankingLength){
            prevNode = nextNode;
            counter++;
            nextNode = nextNode->next;
        }

        if(counter<rankingLength){
            //inserimento alla fine
            if(nextNode == NULL){
                prevNode->next = newNode;
                //(head) = headBackup;
            } else{
                //inserimento in mezzo
                if(prevNode != NULL) {
                    newNode->next = prevNode->next;
                    prevNode->next = newNode;
                    //(head) = headBackup;
                } else {
                    //inserimento in testa
                    newNode->next = (head);
                    (head) = newNode;
                }
            }
        }


    }

    return head;
}

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

    setNodesNumber(nodesNumber);

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

            head = insertNode(head, dijkstra(adjacencyMatrix), graphIndex, rankingLength);
            print_list(head, rankingLength);
            graphIndex++;

        }

    }

    return 0;

}


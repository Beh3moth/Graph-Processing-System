#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * The method takes a line containing two numbers and puts the values in nodes and in rankingLength.
 * @param input is the input's first line.
 * @param nodesNumber is the number of nodes (long long int).
 * @param rankingLength is the length of the rank (long long int).
 */
void takeFirstTwoNumbers(char * input, long long int * nodesNumber, long long int * rankingLength) {
    char * endPtr;
    *nodesNumber = strtol(input, &endPtr, 10);
    *rankingLength = strtol(endPtr, &endPtr, 10);
}

//MATRIX MANAGEMENT FUNCTIONS

/**
 * The function
 * @param adjacencyMatrix is a pointer to the beginning of an array row.
 * @param nodesNumber is the number of nodes of a graph.
 * @param line is the line to put in the array.
 */
void fillAdjacencyMatrix(long long int * adjacencyMatrix, long long int nodesNumber, char * line){
    for(int j=0; j<nodesNumber; j++){
        if(*line == ','){
            line++;
        }
        *(adjacencyMatrix + j) = strtol(line, &line, 10);
    }
}

//PRIORITY QUEUE MANAGEMENT FUNCTIONS

void insertElement(long long int * priorityQueue, long long int graphIndex, long long int newDistanceValue, long long int * priorityQueueMinValue, long long int * priorityQueueMinIndex, long long int * priorityQueueSize){
    if( *(priorityQueue + graphIndex) != DELETED && (*(priorityQueue + graphIndex) == UNDEFINED || newDistanceValue < *(priorityQueue + graphIndex)) ){
        *(priorityQueue + graphIndex) = newDistanceValue;
        if( newDistanceValue < *priorityQueueMinValue || *priorityQueueMinValue==UNDEFINED || *priorityQueueMinValue==DELETED ){
            *priorityQueueMinValue = newDistanceValue;
            *priorityQueueMinIndex = graphIndex;
        }
        (*priorityQueueSize)++;
    }
}

long long int findMinValueIndex(const long long int * priorityQueue, long long int nodesNumber){
    long long int minValueLocation = 0;
    long long int minValue = 9223372036854775807;
    for(long long int i=1; i<nodesNumber; i++){
        if( *(priorityQueue + i) <= minValue && *(priorityQueue + i)!=UNDEFINED && *(priorityQueue + i)!=DELETED ){
            minValue = *(priorityQueue+i);
            minValueLocation = i;
        }
    }
    return  minValueLocation;
}

void deleteElement(long long int * priorityQueue, long long int graphIndex, long long int * priorityQueueMinValue, long long int * priorityQueueMinIndex, long long int * priorityQueueSize, long long int nodesNumber){

    if( *(priorityQueue + graphIndex) != DELETED && *(priorityQueue + graphIndex) != UNDEFINED){
        *(priorityQueue + graphIndex) = DELETED;
        long long int newMinIndex = findMinValueIndex(priorityQueue, nodesNumber);
        (*priorityQueueMinIndex) = newMinIndex;
        (*priorityQueueMinValue) = (*priorityQueue + newMinIndex);
    }
    (*priorityQueueSize)--;

}

//DIJKSTRA MANAGEMENTS FUNCTIONS

long long int dijkstra(long long int nodesNumber, long long int matrix[nodesNumber][nodesNumber]){

    //It indicates the distance from source to vertex of the i-node.
    long long int distances[nodesNumber];
    //The i-element is the min distance found for the i-node
    long long int priorityQueue[nodesNumber];
    long long int priorityQueueMinValue = 0;
    long long int priorityQueueMinIndex = 0;
    long long int priorityQueueSize = 0;
    //It indicates if the i-element is visited or not
    bool visited[nodesNumber];

    //Initialization
    for(int i=0; i < nodesNumber; i++){
        distances[i] = INFINITE;
        priorityQueue[i] = UNDEFINED;
        visited[i] = false;
    }
    distances[0] = 0;
    insertElement(&priorityQueue[0], 0, 0, &priorityQueueMinValue, &priorityQueueMinIndex, &priorityQueueSize);

    while(priorityQueueSize != 0){

        long long int index = priorityQueueMinIndex;
        long long int minValue = priorityQueueMinValue;
        //The node is deleted and set as visited.
        deleteElement(&priorityQueue[0], index, &priorityQueueMinValue, &priorityQueueMinIndex, &priorityQueueSize, nodesNumber);
        visited[index] = true;

        //If the distance of the node is bigger in the distances array than in the heap
        if(distances[index]==INFINITE || (distances[index] >= minValue && distances[index]!=INFINITE)){
            //For every node index
            for(int i=0; i<nodesNumber; i++){
                //If the node is set as not visited
                long long int newDist;
                if(!visited[i]){
                    if(distances[index]==INFINITE){
                        if(matrix[index][i]!=0){
                            newDist = distances[index] + matrix[index][i] + 1;
                        }
                        else {
                            newDist = INFINITE;
                        }
                    }
                    else {
                        if(matrix[index][i]!=0){
                            newDist = distances[index] + matrix[index][i] ;
                        }
                        else {
                            newDist = INFINITE;
                        }
                    }
                    if( newDist!=INFINITE && (newDist < distances[i] || distances[i]==INFINITE) ){
                        distances[i] = newDist;
                        insertElement(&priorityQueue[0], i, newDist, &priorityQueueMinValue, &priorityQueueMinIndex, &priorityQueueSize);
                    }
                }
            }
        }

    }

    long long int sum = 0;

    for(int i=0; i<nodesNumber; i++){
        if(distances[i]!=INFINITE){
            sum += distances[i];
        }
    }

    printf("%lld\n", sum);
    return sum;

}

//RANK FUNCTIONS

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

    //head insertion
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
            //tail insertion
            if(nextNode == NULL){
                prevNode->next = newNode;
                //(head) = headBackup;
            } else{
                //middle insertion
                if(prevNode != NULL) {
                    newNode->next = prevNode->next;
                    prevNode->next = newNode;
                    //(head) = headBackup;
                } else {
                    //head insertion
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
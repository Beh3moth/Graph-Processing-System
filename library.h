#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#define INFINITE -1
#define UNDEFINED -2
#define DELETED -3

//TEXT MANAGEMENT FUNCTIONS

void takeFirstTwoNumbers(char * input, long long int * nodesNumber, long long int * rankingLength) {
    char * endPtr;
    *nodesNumber = strtol(input, &endPtr, 10);
    if(*endPtr == ' ' || *endPtr == ','){
        endPtr++;
    }
    *rankingLength = strtol(endPtr, &endPtr, 10);
}

//MATRIX MANAGEMENT FUNCTIONS

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
    fputs("\n", stdout);
}

node_t* insertNode(node_t * head, long long int sumValue, long long int graphIndex, long long int rankingLength){

    node_t *newNode, *prevNode, *nextNode;

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

#endif //UNTITLED_LIBRARY_H

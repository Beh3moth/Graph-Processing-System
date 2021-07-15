#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#define INFINITE -1

//TEXT MANAGEMENT METHODS

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

//MATRIX MANAGEMENT METHODS

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

//DIJKSTRA MANAGEMENTS METHODS

long long int nodes = 0;

void setNodesNumber(long long int v){
    nodes = v;
}

long long int minDistance(const long long int dist[nodes], const bool sptSet[nodes])
{
    // Initialize min value
    long long int min = INFINITE;
    long long int min_index = INFINITE;

    for (int v = 0; v < nodes; v++) {
        if (sptSet[v] == false && ((dist[v] <= min && dist[v]!=INFINITE) || min == INFINITE)) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

long long int dijkstra(long long int graph[nodes][nodes]){

    //The output array. dist[i] will hold the shortest distance from src to i
    long long int dist[nodes];

    bool sptSet[nodes]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (long long int i = 0; i < nodes; i++){
        dist[i] = INFINITE;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[0] = 0;

    // Find shortest path for all vertices
    for (long long int count = 0; count < nodes - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        long long int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < nodes; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INFINITE && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
    }

    long long int distanceSum = 0;

    for(int i=0; i<nodes; i++){
        if(dist[i]!=INFINITE){
            distanceSum += dist[i];
        }
    }

    return  distanceSum;

}

//LINKED LIST MANAGEMENT METHODS



#endif //UNTITLED_LIBRARY_H

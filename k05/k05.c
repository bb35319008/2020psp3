#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE    1
#define FALSE   0

typedef struct tagStation {
    char name[20];
    char kanji[16];
} Station;

#define MAX_STATIONS 8
Station ArrayStation[MAX_STATIONS] = {
    {"akasako", "赤迫"},
    {"nagasakidaigakumae", "長崎大学前"},
    {"nagasakiekimae", "長崎駅前"},
    {"shinchichukagai", "新地中華街"},
    {"ishibashi", "石橋"},
    {"sofukuji", "崇福寺"},
    {"shiminkaikan", "市民会館"},
    {"hotarujaya", "蛍茶屋"},
};

int AdjacencyMatrix[MAX_STATIONS][MAX_STATIONS] = {
    {0,  5,  0,  0,  0,  0,  0,  0},
    {5,  0, 16,  0,  0,  0,  0,  0},
    {0, 16,  0,  7,  0,  0,  5,  0},
    {0,  0,  7,  0,  7,  6, 10,  0},
    {0,  0,  0,  7,  0,  0,  0,  0},
    {0,  0,  0,  6,  0,  0, 10,  0},
    {0,  0,  5, 10,  0, 10,  0,  6},
    {0,  0,  0,  0,  0,  0,  6,  0},
};

//  ダイクストラ法で使用する構造体(使っても使わなくても良い)
typedef struct tagNodeInfo {
    int cost;
    int fix;
    int from;
} NodeInfo;

void PrintStationName(int index)
{
    printf("%s\n", ArrayStation[index].kanji);
}

typedef int Item;
Item ErrorItem = -1;


#define STACK_SIZE  10
Item Stack[STACK_SIZE];
int SP;

void StackInit(void)
{
    SP = -1;
}

void StackPush(Item value)
{
    if (SP >= STACK_SIZE) {
        printf("Stack Overflow\n");
        return;
    }

    Stack[++SP] = value;
}

Item StackPop(void)
{
    if (SP < 0) {
        printf("Stack Underflow\n");
        return ErrorItem;
    }

    return Stack[SP--];
}

Item StackTop(void)
{
    if (SP < 0) {
        printf("Stack Underflow\n");
        return ErrorItem;
    }

    return Stack[SP];    
}

int StackIsEmpty(void)
{
    if (SP < 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}



#define UNVISITED   0
#define VISITED 1

void DepthFirstSearch(int size, int matrix[size][size], int start)
{
    //  ここを実装する
    int visited[size], i, j, n=0, c=0, x;

    for(i=0; i < size; i++){
        visited[i] = 0;
    }

    StackInit();
    StackPush(start);

    printf("===== 深さ優先探索 =====\n");
    printf("=== ルート ===\n");
    while(StackIsEmpty() == FALSE){
        i = StackPop();
        j = 0;
        if(visited[i] != 1){
            visited[i] = 1;
            PrintStationName(i);
            n++;
            if(n != MAX_STATIONS){
                printf("  ↓  \n");
            }

            c = 0;
            while(j < size){
                if(matrix[i][j] != 0){
                    StackPush(j);
                    c++;
                    x = j;
                }
                j++;
            }

            if(n != 1 && n != MAX_STATIONS && c == 1){
                PrintStationName(x);
                printf("  ↓  \n");
            }
        }
    }

    return;
}



#define QUEUE_MAX   10
Item Queue[QUEUE_MAX];
int QueueIn;
int QueueOut;
int QueueCount;

void InitQueue()
{
    QueueIn = 0;
    QueueOut = 0;
    QueueCount = 0;
}

void EnQueue(Item value)
{
    if (QueueCount >= QUEUE_MAX) {
        printf("Queue Overflow\n");
        return;
    }

    Queue[QueueIn] = value;
    QueueIn ++;
    if (QueueIn >= QUEUE_MAX) {
        QueueIn = 0;
    }

    QueueCount++;
}

Item DeQueue()
{
    Item value;

    if (QueueCount <= 0) {
        printf("Queue Underflow\n");
        return ErrorItem;
    }

    value = Queue[QueueOut];
    QueueOut++;
    if (QueueOut >= QUEUE_MAX) {
        QueueOut = 0;
    }

    QueueCount--;
    return value;
}

int QueueIsEmpty()
{
    if (QueueCount == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}


void BreadthFirstSearch(int size, int matrix[size][size], int start)
{
    //  ここを実装する
    int visited[size], i, j, n, z, x=0;

    for(i=0; i < size; i++){
        visited[i] = 0;
    }

    InitQueue();
    EnQueue(start);

    printf("\n===== 幅優先探索 =====\n");
    printf("=== ルート ===\n");
    while(QueueIsEmpty() == FALSE){
        i = DeQueue();
        j = 0;
        if(visited[i] != 1){
            visited[i] = 1;
            if(matrix[i][n] == 0 && matrix[n][i] == 0){
                for(z=0; z < size; z++){
                    if(matrix[i][z] != 0 && matrix[n][z] != 0){
                        PrintStationName(z);
                        printf("  ↓  \n");
                    }
                }
            }
            PrintStationName(i);
            x++;
            if(x != MAX_STATIONS){
                printf("  ↓  \n");
            }
            n = i;
            while(j < size){
                if(matrix[i][j] != 0){
                    EnQueue(j);
                }
                j++;
            }
        }
    }

    return;
}


#define INF_COST    9999

int SearchGraphByDijkstra(int start, int goal, int size, int matrix[size][size])
{
    //  ここを実装する
    int cost[size], visited[size], i, min_index, j, n, min=INF_COST, c, from[size], index, route[size];

    for(i=0; i < size; i++){
        cost[i] = INF_COST;
        visited[i] = 0;
        from[i] = 0;
        route[i] = 0;
    }

    cost[start] = 0;
    from[start] = -1;

    min_index = start;
    while(1){
        min = INF_COST;
        for(n=0; n < size; n++){
            if(visited[n] == 0){
                if(min > cost[n]){
                    min = cost[n];
                    min_index = n;
                    if(min_index == goal){
                        printf("\n===== ダイクストラ法 =====\n");
                        printf("=== ルート ===\n");
                        index = goal;
                        i = 0;
                        while(from[index] != -1){
                            route[i] = index;
                            index = from[index];
                            i++;
                        }

                        for(i=size; i >= 0; i--){
                            if(route[i] != 0){
                                if(route[i] == -1){
                                    route[i] = 0;
                                }

                                PrintStationName(route[i]);
                                if(i != 0){
                                    printf("  ↓  \n");
                                }
                            }
                        }
                        return cost[min_index];
                    }
                }
            }
        }

        visited[min_index] = 1;

        for(j=0; j < size; j++){
            if(matrix[min_index][j] != 0){
                if(visited[j] == 0){
                    c = cost[min_index] + matrix[min_index][j];
                    if(cost[j] > c){
                        cost[j] = c;
                        from[j] = min_index;
                    }
                }
            }
        }
    }
}



int main(void)
{
    int cost;

    DepthFirstSearch(MAX_STATIONS, AdjacencyMatrix, 0);
    BreadthFirstSearch(MAX_STATIONS, AdjacencyMatrix, 0);

    cost = SearchGraphByDijkstra(0, 7, MAX_STATIONS, AdjacencyMatrix);
    printf("Time Required: %d\n", cost);

    return 0;
}
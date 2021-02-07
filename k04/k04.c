#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id;
    char name[19];  //  市の名前、UTF-8対応
    float members;  //  世帯人員
    int total;      //  食料合計
    int grain;      //  穀類
    int seafood;    //  魚介類
    int meat;       //  肉類
    int milk;       //  乳卵類
    int vegetable;  //  野菜類
    int fruit;      //  果物
    int seasoning;  //  調味料
    int snack;      //  菓子類
    int cocking;    //  調理料理
    int drink;      //  飲料
    int liquor;     //  酒類
    int eatout;     //  外食
} City;

#define DEBUG
#define MAX_CITY    47


void PrintCity(City city)
{
    printf("%d, %s, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
        city.id, city.name, city.members, city.total, 
        city.grain, city.seafood, city.meat, city.milk, city.vegetable, city.fruit,
        city.seasoning, city.snack, city.cocking, city.drink, city.liquor, city.eatout);
}

void PrintArray(City city[], int size)
{
    int i;

    for (i=0; i<size; i++) {
        PrintCity(city[i]);
    }
}

int LoadData(City arrayCity[])
{
    char buf[256];
    FILE* fp;

    fp = fopen("consumption.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        return -1;
    }

    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%[^,],%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
            &(arrayCity[cn].id), arrayCity[cn].name, &(arrayCity[cn].members), &(arrayCity[cn].total), 
            &(arrayCity[cn].grain),  &(arrayCity[cn].seafood),  &(arrayCity[cn].meat), &(arrayCity[cn].milk), 
            &(arrayCity[cn].vegetable),  &(arrayCity[cn].fruit),  &(arrayCity[cn].seasoning),  &(arrayCity[cn].snack),
            &(arrayCity[cn].cocking),  &(arrayCity[cn].drink),  &(arrayCity[cn].liquor),  &(arrayCity[cn].eatout));
#ifdef DEBUG
        PrintCity(arrayCity[cn]);
#endif
        cn++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        return -1;
    }

    return cn;
}

void swap(City *c1, City *c2){
    City tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}


void BubbleSort(City arrayCity[], int size)
{
    //  ここを実装する
    int pos, cnt=0;

    for(pos=0; pos < size-1; pos++){
        if(arrayCity[pos].total > arrayCity[pos+1].total){
            swap(&arrayCity[pos], &arrayCity[pos+1]);
            cnt++;
        }
    }

    if(cnt != 0){
        BubbleSort(arrayCity, size);
    }

    return;
}


void QuickSort(City arrayCity[], int left, int right)
{
    //  ここを実装する
    int pivot, i, j;

    if(left >= right){
        return;
    }

    pivot = arrayCity[left].seafood;
    i = left;
    j = right;
    
    while(i < j){
        while(i <= right){
            if(arrayCity[i].seafood > pivot){
                break;
            }
            i++;
        }

        while(j >= left){
            if(arrayCity[j].seafood <= pivot){
                break;
            }
            j--;
        }

        if(i >= j){
            swap(&arrayCity[left], &arrayCity[j]);
            QuickSort(arrayCity, left, j-1);
            QuickSort(arrayCity, j+1, right);
        }else{
            swap(&arrayCity[i], &arrayCity[j]);
            continue;
        }
    }
}

void BuildHeap(City arrayCity[], int size);

void PartialHeap(City arrayCity[], int size, int node);

int i = MAX_CITY;

void HeapSort(City arrayCity[], int size)
{
    //  チャレンジ問題(1)
    //  ここを実装する

    if(i <= 1){
        return;
    }

    BuildHeap(arrayCity, size);

    while(i > 1){
        swap(&arrayCity[0], &arrayCity[i-1]);
        i--;

        BuildHeap(arrayCity, size-1);
    }
}


void MergeSort(City arrayCity[], int left, int right)
{
    //  チャレンジ問題2
    //  ここを実装する
    int mid, i, j, s;
    City buff[MAX_CITY];

    if(left >= right){
        return;
    }

    mid = left + (right - left)/2;
    MergeSort(arrayCity, left, mid);
    MergeSort(arrayCity, mid+1, right);

    for(i = left; i <= mid; i++){
        buff[i] = arrayCity[i];
    }

    for(j = mid+1; j <= right; j++){
        buff[j] = arrayCity[j];
    }

    i = left;
    j = mid+1;
    for(s = left; s <= right; s++){
        if(i > mid){
            while(s <= right){
                arrayCity[s] = buff[j];
                j++;
                s++;
            }
            break;
        }else if(j > right){
            while(s <= right){
                arrayCity[s] = buff[i];
                i++;
                s++;
            }
            break;
        }else if (buff[i].liquor <= buff[j].liquor){
            arrayCity[s] = buff[i];
            i++;
        }else{
            arrayCity[s] = buff[j];
            j++;
        }
    }
}

int main(void)
{
 
    //  事前準備。データの読み込み、配列の作成
    City* arrayCity;
    int cn;
    arrayCity = (City*)malloc(sizeof(City) * MAX_CITY);
    cn = LoadData(arrayCity);
    if (cn == -1) {
        exit(EXIT_FAILURE);
    }

    //  食料品合計で並び替え
    printf("===== Sorted by total =====\n");
    BubbleSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);

    //  魚介類で並び替え   
    printf("===== Sorted by seafood =====\n");
    QuickSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);

    printf("===== Sorted by liquor =====\n");
    MergeSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);

    printf("===== Sorted by meat =====\n");
    HeapSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);



    //  後処理
    free(arrayCity);

    return 0;
}

void BuildHeap(City arrayCity[], int size)
{
    int last_node, node;

    last_node = size/2 - 1;
    for(node = last_node; node >= 0; node--){
        PartialHeap(arrayCity, size, node);
    }

    return;
}

void PartialHeap(City arrayCity[], int size, int node)
{
    int left, right, c;

    left = 2*node + 1;
    right = 2*node + 2;

    if(left > size || (arrayCity[right].meat > arrayCity[node].meat && arrayCity[left].meat > arrayCity[node].meat)){
        return;
    }else{
        if(arrayCity[right].meat < arrayCity[left].meat && arrayCity[right].meat < arrayCity[node].meat){
            swap(&arrayCity[right], &arrayCity[node]);
            c = right;
        }

        if(arrayCity[left].meat < arrayCity[right].meat && arrayCity[left].meat < arrayCity[node].meat){
            swap(&arrayCity[left], &arrayCity[node]);
            c = left;
        }
    }

    if(c == right){
        PartialHeap(arrayCity, size, right);
    }

    if(c == left){
        PartialHeap(arrayCity, size, left);
    }
}
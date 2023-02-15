#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <windows.h>

using namespace std;
void bubbleSort(int array[], int size) {

  for (int step = 0; step < size; ++step) {
    for (int i = 0; i < size - step; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

int printarr(int tab[],int n){
    for(int i=0;i<n;i++){
        std::cout << tab[i] << " ";
    }
    return 0;
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
              min_idx = j;
            }
        }
        if (min_idx!=i){
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

void insertionSort(int *tab, int n){
    int pom, j;
    for(int i=1; i<n; i++){
        pom = tab[i];
        j = i-1;
        while(j>=0 && tab[j]>pom){
            tab[j+1] = tab[j];
            --j;
        }
        tab[j+1] = pom;
    }
}

int binarySearch(int a[], int x, int low, int high){
    if (high <= low)
        return (x > a[low]) ?
               (low + 1) : low;
    int mid = (low + high) / 2;
    if (x == a[mid])
        return mid + 1;
    if (x > a[mid])
        return binarySearch(a, x,mid + 1, high);
    return binarySearch(a, x, low,mid - 1);
}

void binarySort(int a[], int n){
    for (int i = 1; i < n; ++i){
        int j = i - 1;
        int key = a[i];
        int pos = binarySearch(a, key, 0, j);
        while (j >= pos){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int lic,n, pyt,pyt1;
    int tab1[999];
    clock_t start, end;


    cout<<"Skip poczatek?(nie 1/2 tak)"<<endl;
    cin>>pyt1;
    int tab[999];
    if(pyt1==1){
        do{
            cout<<"Wpisz ile bedzie cyfr(x>=8)"<<endl;
            cin>>n;
        }while(n<8);

        tab[n];

        for(int i=0;i<n;i++){
        cin>>lic;
        tab[i]=lic;
        }
    }else{
        n=8;
        for(int i=0;i<8;i++){
            tab[i]=rand() % 10;
        }
        cout<<"Liczby: "<<printarr(tab,n)<<endl;
    }

    cout<<""<<endl;
    cout<<"Wybierz typ sortowania"<<endl;
    cout<<"1) Bubble"<<endl;
    cout<<"2) Selection"<<endl;
    cout<<"3) insertion"<<endl;
    cout<<"4) binary"<<endl;
    cin>>pyt;
    start = clock();
    switch(pyt){
        case 1:
        cout<<"bubbleSort"<<endl;
        bubbleSort(tab,n);
        Sleep(10);
        break;
        case 2:
        selectionSort(tab,n);
        Sleep(10);
        break;
        case 3:
        insertionSort(tab,n);
        Sleep(10);
        break;
        case 4:
        binarySort(tab,n);
        Sleep(10);
        break;
    }
    end = clock();
    cout<<"Czas(ms): "<<end-start<<endl;
    printarr(tab,n);

}

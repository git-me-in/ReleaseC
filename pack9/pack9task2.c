#include <stdio.h>

void merge(int a[], int mid, int left, int right){
    int la = mid - left + 1;
    int ra = right - mid;

    int L[la];
    int R[ra];
    for(int i = 0; i < la; i++)
        L[i] = a[left + i];
    for(int j = 0; j < ra; j++)
        R[j] = a[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while(i < la && j < ra){
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < la)
        a[k++] = L[i++];
    while (j < ra)
        a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, mid, left, right);
    }
}

int main(void){
    FILE *fin = fopen("input.txt", "rb");
    FILE *fout = fopen("output.txt", "wb");

    int N;
    fread(&N, sizeof(int), 1, fin);

    int arr[N];
    for(int i = 0; i < N; i++)
        fread(&arr[i], sizeof(int), 1, fin);

    int left = 0;
    int right = N - 1;
    mergeSort(arr, left, right);
    for(int i = 0; i < N; i++)
        fwrite(&arr[i], sizeof(int), 1, fout);
}
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
   int t=*a;
   *a=*b;
   *b=t;
}


void quicksort(int A[], int start, int end){ //start and end are indexes of first and last values
   if (end<start){
    return;
   } 
   int pivotindex = partition(A, start, end);
   quicksort(A,start, pivotindex-1);
   quicksort(A,pivotindex+1, end);

}

int partition(int A[], int start, int end){ //returns the pivot index after first sort
  int pivot=A[end];
  int i=start-1;
  for (int j=start;j<=end;j++){
    if(A[j]<=pivot){
      i++;
      swap(&A[i], &A[j]);
    }
  }
  return i;

}




int main(){

 int n, i, A[1000], B[1000];
 int min,minindex,k,intermed;
 clock_t begin, ending;
 float timepassed;
 printf("n = ");
scanf("%d", &n);

 for(i=0;i<n;i++){
  A[i]=rand()%100;
  B[i]=A[i];  //B este array ul intermediar, care mentine valorile initiale
  printf(" %d\t",A[i]);
}



begin=clock();
//linear selection
for (i=0;i<n;i++){
  min=A[i];
  minindex=i;// fara aceasta, pot aparea valori gresite
  for (k=i+1;k<n;k++){
     if (A[k]<min){
        min=A[k];
        minindex=k;
     }}

     A[minindex]= A[i];
     A[i]=min;
     }


printf("\n\nSelection Sorting:\n");

for(i=0;i<n;i++){
  printf(" %d\t",A[i]);
 }

 for(i=0;i<n;i++){
  A[i]=B[i];  
}
ending=clock();
 timepassed=(double)(ending- begin) / CLOCKS_PER_SEC;
printf("\nTime necessary: %f microseconds.\n\n", timepassed*1000000);


//Bubble Sorting
begin=clock();
for(i=0;i<n-1;i++){
  for(k=0;k<n-1-i;k++){
    if (A[k]>A[k+1]){
       intermed=A[k+1];
       A[k+1]=A[k];
       A[k]=intermed;
       
    }

  } 

} 
printf("Bubble Sorting:\n");
for(i=0;i<n;i++){
  printf("%d\t",A[i]);
 }

  for(i=0;i<n;i++){
  A[i]=B[i];  
}
ending=clock();
timepassed=(double)(ending- begin) / CLOCKS_PER_SEC;
printf("\nTime necessary: %f\n\n", timepassed*1000000);


//Insertion Sorting
begin=clock();
for(i=1;i<n;i++){
    intermed=A[i];
   for(k=i-1;k>=0;k--){
     if(intermed<A[k]){
      A[k+1]=A[k];
      A[k]=intermed;
     }
   }
}

printf("Insertion Sorting:\n");
for(i=0;i<n;i++){
  printf("%d\t",A[i]);
 }

  for(i=0;i<n;i++){
  A[i]=B[i];  
}
ending=clock();
timepassed=(double)(ending- begin) / CLOCKS_PER_SEC;
printf("\nTime necessary: %f\n\n", timepassed*1000000);



//Quick Sort
begin=clock();
quicksort(A,0,n-1);

printf(" Quick Sort:\n");
for(i=0;i<n;i++){
  printf(" %d\t",A[i]);
 }

  for(i=0;i<n;i++){
  A[i]=B[i];  
}

ending=clock();
timepassed=(double)(ending- begin) / CLOCKS_PER_SEC;
printf("\nTime necessary: %f\n\n", timepassed*1000000);

    return(0);
}
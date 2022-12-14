#include <stdio.h>
#include <stdlib.h>

// A utility function to print an array of size n
void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int* insertion(int arr[], int n) {
	int i, key, j;
	int *comp;
	comp = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		key = arr[i];
		j = i - 1;
		comp[i] = 1;	
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
			comp[i]= comp[i] + 1;
		}
		arr[j + 1] = key;
	}
	return comp;
}



void permutations() {
	int i,j,k,l,count=0,totalComp[] = {0,0,0,0};
	
	for(i=1; i <=4; i++) {		
		for(j=1; j <=4; j++) { 
		   if(i==j) {
		   	 continue;
		   }		 
		   for(k=1; k <=4; k++) {
		      if(k==i || k== j) {
		      	continue;
			  }		    
		      for(l=1; l <=4; l++) {
		      	if(l==k || l==i || l==j) {
		      		continue;
				  }
				  ++count;
				printf("Permutation: \n");
				printf("%d %d %d %d\n",i,j,k,l);
				printf("comparison: \n");
				int arr[4];
				arr[0] = i;
				arr[1] = j;
				arr[2] = k;
				arr[3] = l;
				int *comp = insertion(arr,4);
				totalComp[0] += comp[0];
				totalComp[1] += comp[1];
				totalComp[2] += comp[2];
				totalComp[3] += comp[3];
				printArray(comp,4);
			  }
	     }
	    } 
	    printf("Total comparisons: ");
	    printArray(totalComp,4);
	}
	
	printf("count = %d",count);	
}


int main() {
//	int arr[] = { 1,2,3,4 };
  	int arr[] = { 4,1,3,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	permutations();

	return 0;
}


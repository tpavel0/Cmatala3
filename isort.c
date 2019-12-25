#include <stdio.h>
#include <stdlib.h>
#define ArrSize 50
#define LINE 256

void print_array(int *data, int n) {
	int i;
	for(i = 0; i<n; i++) {
		printf("%d, ", *data);
		data++;
	}
	printf("\n");
}

void shift_element(int *arr, int i) {
    int temp=*(arr+i);
    printf("%d \n",temp);
    for (;i >0 ; i--) {
        *(arr+i)=*(arr+i-1);
    }
    *arr = temp;
    
}

void shift_element2(int *arr, int *i) {
    int temp;
	for(temp = *i; (i > arr) && (*(i-1) > temp); i--) {
		*i = *(i-1);
	}
	*i = temp;
}

void insertion_sort(int *arr, int len) {
	int *i, *last = arr + len;
	for(i = arr + 1; i < last; i++){
	 	if(*i < *(i-1))
			shift_element2(arr, i);   
			
		print_array(&arr[0], len);
	}
}

int main()
{

 FILE *myFile;
    myFile = fopen("sort_input.txt", "r");

    //read file into array
    int numberArray[ArrSize];
    int i;

    if (myFile == NULL){
        printf("Error Reading File\n");
        //exit (0);
    }

    for (i = 0; i < ArrSize; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }

    fclose(myFile);
    
	int n = sizeof(numberArray)/sizeof(int);

	print_array(&numberArray[0], n);
	
	shift_element(&numberArray[0],5);
	insertion_sort(&numberArray[0], n);
	
	print_array(&numberArray[0], n);

    return 0;
}


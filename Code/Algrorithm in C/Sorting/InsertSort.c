/* Insert sort implement
/* Worst case O(n^2)
/* Best case O(n)
*/

#include <stdio.h>

#define MAX 10
int g_list[MAX] = {7, 3, 19, 2, 0, 72, 6, 21, 12, 15};

void PrintList(){
	int i = 0;
	for(i = 0; i < MAX; i++){
		printf("%d ", g_list[i]);
	}
	printf("\n");
}

void InsertSort(){
	int i = 0;
	int j = 0;
	int insertNumber = 0;
	for(i = 1; i < MAX; i++){
		j = i;
		insertNumber = g_list[j];
		while(j > 0 && g_list[j] > insertNumber){
			g_list[j] = g_list[j-1];
			j--;
		}
		if(j != i){
			g_list[j] = insertNumber;
		}
	}
}

int main(){
	printf("Input array: \n");
	PrintList();
	
	InsertSort();
	printf("Output array: \n");
	PrintList();
	
	return 0;	
}
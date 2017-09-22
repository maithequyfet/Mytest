/* Bubble sort implement
/* Worst case O(n^2)
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

void BubbleSort(){
	int i = 0;
	int j = 0;
	int temp = 0;
	
	for(i = 0; i < MAX - 1; i++){
		for(j = 0; j < MAX - i - 1; j++){
			if(g_list[j] > g_list[j + 1]){
				temp = g_list[j];
				g_list[j] = g_list[j + 1];
				g_list[j + 1] = temp;
			}
		}
	}
}

int main(){
	printf("Input array: \n");
	PrintList();
	
	BubbleSort();
	printf("Input array: \n");
	PrintList();
	
	return 0;	
}

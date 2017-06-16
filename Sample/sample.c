#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char *gFirstNumber = "222233.0";
char *gSecondNumber = "3393.0";

/* Function to dectect the location of character '." */
int GetPointInfo(char *s){ 
	int i = 0;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == '.'){
			break;
		}
	}
	return i;
}

void AddBeforePoint(int point1, int point2, char *s){
	int i = 0;
	int j = 0;
	int total = 0;
	int surplus = 0;
	i = point1 - 1;
	j = point2 - 1;
	if(point1 > point2){
		for (i;i >= 0; i-- ){
			if(j >= 0){
				total = atoi(gFirstNumber[i]) + atoi(gSecondNumber[j])+ surplus;
			}
			else{
				total = atoi(gFirstNumber[i]) + surplus;
			}
			printf("%d \n", total);
			if(total >= 10){
				surplus = 1;
				total = total % 10;
				s[i + 1] = (char)total;
			}
			else{
				surplus = 0;
				s[i + 1] = (char)total;
			}
			printf("%c\n", s[i+1]);
		
		    j--;
		}
	}
}


int main(){
	char *s = NULL;
	int i = 0;
	int point1 = GetPointInfo(gFirstNumber);
	int point2 = GetPointInfo(gSecondNumber);
	s = (char*)malloc(sizeof(char)*100);
	AddBeforePoint(point1,point2,s);
	for(i = 0; i < strlen(s); i++){
	    printf("%c",s[i]);
	}
	free(s);
	return 0;
}
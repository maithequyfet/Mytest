#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "DegitDefine.h"

char gFirstNumber[100] = "222232222222222222223.3212002201";
char gSecondNumber[100] = "93393.624";

/* Function to dectect the location of character '.' */
int GetPointInfo(char *s){
	int i = 0;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == '.'){
			break;
		}
	}
	return i;
}

/* Covert a single letter to the correspond digit */
int CovertStringToDigit(char s){
	int temp;
    switch(s){
	    case 48:
		    temp = 0;
			break;
		case 49:
		    temp = 1;
			break;
		case 50:
		    temp = 2;
			break;
		case 51:
		    temp = 3;
			break;
		case 52:
		    temp = 4;
			break;
		case 53:
		    temp = 5;
			break;
		case 54:
		    temp = 6;
			break;
		case 55:
		    temp = 7;
			break;
		case 56:
		    temp = 8;
			break;
		case 57:
		    temp = 9;
			break;
		default:
			return -1;
    }
	return temp;
}

/* Covert a digit to the correspond letter */
char CovertDigitToString(int num){
	char temp;
    switch(num){
	    case 0:
		    temp = 48;
			break;
		case 1:
		    temp = 49;
			break;
		case 2:
		    temp = 50;
			break;
		case 3:
		    temp = 51;
			break;
		case 4:
		    temp = 52;
			break;
		case 5:
		    temp = 53;
			break;
		case 6:
		    temp = 54;
			break;
		case 7:
		    temp = 55;
			break;
		case 8:
		    temp = 56;
			break;
		case 9:
		    temp = 57;
			break;
		default:
			return -1;
    }
	return temp;
}

/* Function to add natural parts of two number */
char AddBeforePoint(int point1, int point2,char *s){
	int i = 0;
	int j = 0;
	int total = 0;
	int surplus = 0;
	i = point1 - 1;
	j = point2 - 1;
	s[0] = 49;    /* ASCII of zero */

	for (i;i >= 0; i--){
		if(j >= 0){
			total = CovertStringToDigit(gFirstNumber[i]) + CovertStringToDigit(gSecondNumber[j])+ surplus;
		}
		else{
			total = CovertStringToDigit(gFirstNumber[i]) + surplus;
		}
		if(total >= 10){
			surplus = 1;
			total = total % 10;
			s[i + 1] = CovertDigitToString(total);
		}
		else{
			surplus = 0;
			s[i + 1] = CovertDigitToString(total);
		}
		total = 0;
	    j--;
	}

	s[0] = CovertDigitToString(surplus);
	return *s;
}

/* Function to add fractional part of two number */
char AddAfterPoint(int point1, int point2,char *s){
    int i = 0;
	int j = 0;
	int k = 0;
	int total = 0;
	int surplus = 0;
	int temp = 0;
	temp = point1 + strlen(gSecondNumber) - point2 - 1;
	s[point1 + 1] = 46;									/* ASCII of '.' */
	s[point1 + 2] = 49; 							/* ASCII of zero */     							/* ASCII of '.' */

	i = strlen(gFirstNumber) - 1;
	j = strlen(gSecondNumber) - 1;

	for(i; i > point1; i--){
		if(i > temp){
			total = CovertStringToDigit(gFirstNumber[i]);
		}
		else{
			total = CovertStringToDigit(gFirstNumber[i]) + CovertStringToDigit(gSecondNumber[j])+ surplus;
			j--;
		}

		if(total >= 10){
			surplus = 1;
			total = total % 10;
			s[i + 2] = CovertDigitToString(total);
		}
		else{
			surplus = 0;
			s[i + 2] = CovertDigitToString(total);
		}
		total = 0;
	}
	s[point1 + 2] = CovertDigitToString(surplus);

	return *s;
}

/* Remove zero letter at head of string and before the point */
void RemoveZeroLetter(char *s){
	int i = 0;
	int len = strlen(s);
	int point = 0;
	if(s[0] == 48){
	    for(i = 0; i < len; i++){
		    s[i] = s[i+1];
		}
		s[len - 1] = NULL;
		len = len - 1;
	}

    point = GetPointInfo(s);
	if(s[point + 1] == 48){
		for(i = point + 1; i < len; i++){
		    s[i] = s[i+1];
		}
		s[len - 1] = NULL;
	}

}

int main(){
	char *s;
	int point1 = GetPointInfo(gFirstNumber);
	int point2 = GetPointInfo(gSecondNumber);

	s = (char*)malloc(sizeof(s)*100);

	*s = AddBeforePoint(point1,point2,s);
	*s = AddAfterPoint(point1,point2,s);

	printf("%s\n",s);
	RemoveZeroLetter(s);
	printf("%s\n",s);

	free(s);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

char gFirstNumber[100] = "222233.3211";
char gSecondNumber[100] = "3393.924";

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
	s[0] = 49;
	
	for (i;i >= 0; i--){
		if(j >= 0){
			total = CovertStringToDigit(gFirstNumber[i]) + CovertStringToDigit(gSecondNumber[j])+ surplus;
		}
		else{
			total = CovertStringToDigit(gFirstNumber[i]) + surplus;
		}
		//printf("%d\n", total);
		if(total >= 10){
			surplus = 1;
			total = total % 10;
			s[ + 1] = CovertDigitToString(total);
		}
		else{
			surplus = 0;
			s[i + 1] = CovertDigitToString(total);
		}
		//printf("%c\n", s[i+1]);
		total = 0;
	    j--;
	}
	
	s[0] = CovertDigitToString(surplus);
	return *s;
}

AddAfterPoint(int point1, int point2,char *s){
    int i = 0;
	int j = 0;
	int k = 0;
	int total = 0;
	int surplus = 0;
	int temp = 0;
	temp = point1 + strlen(gSecondNumber) - point2;
	s[point1 + 1] = 49; 							/* ASCII of 0 */
	s[point1] = 46;     							/* ASCII of '.' */
	
	i = strlen(gFirstNumber) - 1;
	j = strlen(gSecondNumber) - 1;
	
	for(i; i > point1; i--){
		if(i >= temp){
			total = CovertStringToDigit(gFirstNumber[i]);
		}
		else{
			total = CovertStringToDigit(gFirstNumber[i]) + CovertStringToDigit(gSecondNumber[j])+ surplus;
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
	s[point1 + 1] = CovertDigitToString(surplus);
	
	return *s;
}


int main(){
	char *s;
	int i = 0;
	int point1 = GetPointInfo(gFirstNumber);
	int point2 = GetPointInfo(gSecondNumber);
	s = (char*)malloc(sizeof(s)*100);
	*s = AddBeforePoint(point1,point2,s);
	*s = AddAfterPoint(point1,point2,s);
	printf("%s\n",s);
	free(s);
	return 0;
}
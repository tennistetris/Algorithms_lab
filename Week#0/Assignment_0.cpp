#include <stdio.h>
#include <stdlib.h>

int stackystr(char*,int,int,int,int,int,char);
int stackystrformula(int n);
int stackyperm(char*,int,int,int,int,int,char);

int main(){
char *Str;
int Num_Strings_formula,Num_strings_1,Num_strings_2,Num_strings;
printf("Enter a positive integer(<=10) \n");
int n,count = 0,i=1,pos=1,neg=0;
scanf("%d",&n);
Str= (char*)malloc((2*n+1)*sizeof(char));
Str[0] = '+';
printf("Printing all stacky Strings of order n(%d) \n",n);
Num_strings_1 = stackystr(Str,n,count,i,pos,neg,'+');
Num_strings_2 = stackystr(Str,n,count,i,pos,neg,'-');
Num_strings = Num_strings_1+Num_strings_2;
printf("Number of strings : %d \n",Num_strings);

printf("Enter n : \n");
scanf("%d",&n);
Num_Strings_formula = stackystrformula(n);
printf("No. of strings as determined by formula : %d \n",Num_Strings_formula);



return 1;
}

int stackystr(char* Str,int n,int count,int i,int pos,int neg,char call){


	if(call == '+' && (pos<n)){
		Str[i] = call;
		i++;pos++;
		int count1 ,count2;
		count1 = stackystr(Str,n,count,i,pos,neg,'+');
		count2 = stackystr(Str,n,count,i,pos,neg,'-');
		count = count1 + count2;
		return count;
	}


	if(call == '-' && (pos>neg)){
		Str[i] = call;
		i++;neg++;
		if(i == (2*n)){
			count++;
			for (int j = 0;j<2*n;j++){
				printf("%c",Str[j]);
			}
			printf("\n");
			return count;
		}
		else{
			int count1,count2;
			count1 = stackystr(Str,n,count,i,pos,neg,'+');
			count2 = stackystr(Str,n,count,i,pos,neg,'-');
			count = count1 + count2;
			return count;
		}
	}
	return count;
}

int stackystrformula(int n){

  for(int i = 0;i<n;i++){
    
  }

}


int fact(int n , int j){

	int result = 1;

	for(int i = j+1 ;i<=(j+n) ;i++){
		result*=i;
		}
	return result;
}

int stackyperm(char* Str,int n,int count,int i,int pos,int neg,char call){


	if(call == '+' && (pos<n)){
		Str[i] = call;
		i++;pos++;
		int count1 ,count2;
		count1 = stackystr(Str,n,count,i,pos,neg,'+');
		count2 = stackystr(Str,n,count,i,pos,neg,'-');
		count = count1 + count2;
		return count;
	}


	if(call == '-' && (pos>neg)){
		Str[i] = call;
		i++;neg++;
		if(i == (2*n)){
			count++;
			for (int j = 0;j<2*n;j++){
				printf("%c",Str[j]);
			}
			printf("\n");
			return count;
		}
		else{
			int count1,count2;
			count1 = stackystr(Str,n,count,i,pos,neg,'+');
			count2 = stackystr(Str,n,count,i,pos,neg,'-');
			count = count1 + count2;
			return count;
		}
	}
	return count;
}



#include <stdio.h>
#include<time.h>
#include<stdlib.h>


extern void registerme ( );
extern void startgame ( int );
extern int guess ( int );
extern void verifysoln ( int );

unsigned long long playgame1();
unsigned long long playgame2();
unsigned long long playgame3();
unsigned long long playgame4();

int main(){
	registerme();
	clock_t c1,c2;
	unsigned long long a;
	// Game 1
	startgame(1);
	c1 = clock();;
	a = playgame1();
	c2=clock();
	printf("\n    Time Taken = %lf sec \n",(double)(c2-c1)/(double)CLOCKS_PER_SEC);
	verifysoln(a);
	
	// Game 2
	startgame(2);
	c1 = clock();;
	a = playgame2();
	c2=clock();
	printf("\n    Time Taken = %lf sec \n",(double)(c2-c1)/(double)CLOCKS_PER_SEC);
	verifysoln(a);

	// Game 3
	//registerme();
	startgame(3);
	c1 = clock();;
	a = playgame3();
	c2=clock();
	printf("\n    Time Taken = %lf sec \n",(double)(c2-c1)/(double)CLOCKS_PER_SEC);
	verifysoln(a);

	// Game 4
	startgame(4);
	c1 = clock();;
	a = playgame4();
	c2=clock();
	printf("\n    Time Taken = %lf sec \n",(double)(c2-c1)/(double)CLOCKS_PER_SEC);
	verifysoln(a);

	return 1;

}

unsigned long long playgame1(){
	unsigned long long result1,N = 1e8;
	int ret;
	for (unsigned long long i = 1;i<=N;i++){
		ret = guess(i);
		if (ret){
			result1 = i;
			break;
		}
	}
	return result1;
}

unsigned long long playgame2(){
	srand((unsigned int)time(NULL));
	unsigned long long N = 1e8,result1;
	int ret;
	while(1){
		result1 = (1+rand())%N;
		ret = guess(result1);
		if (ret) break;
	}
	return result1;
}

unsigned long long playgame3(){
	int ret_start,ret_end;
	unsigned long long mid,result1,start = 1,end = 1e8;
	while(start<=end){
		ret_start = guess(start);
		if (ret_start == 1){
			result1 = start;
			break;
		}
		ret_end = guess(end);
		mid = (start + end)/2;
		if (ret_end == 2) {
			start = mid;
		}
		else if (ret_end == 3){
			end = mid;
		}
		else if(ret_end == 1){
			result1 = end;
			break;
		}
	}
	return result1;
}

unsigned long long playgame4(){
	long long int start = 1,end = 1e8,c1=1e8/3,c2=(2*(1e8)/3),result1;
	int ret,found = 0,calls=0;
	c1 = (start + end)/3;
	ret = guess(c1);
	calls+=1;
	if (ret == 1){
		return c1;
	}
	printf("\n%lld,%lld,%lld,%lld,%d,%d",start,end,c1,c2,ret,calls);
	while(!found){
		ret = guess(c2);
		calls+=1;
		printf("\n%lld,%lld,%lld,%lld,%d,%d",start,end,c1,c2,ret,calls);
		if(end-start <=1)break;
		if (ret == 2){
			if (c2<c1)end = (start + end)/2;
			else start = (start + end)/2;
			c1 = c2;
			c2 = (start +end -c1);
		}
		if (ret == 3){
			if (c2<c1)start = (start + end)/2;
			else end = (start + end)/2;
			c1=c2;
			c2 = (start +end -c1);
		}
		if (ret ==1){
			result1 = c2;
			found = 1;
			break;
		}
		else{;}
		
	}
	if(found){
		return result1;
	}
	long long rem = (start - end);
	if (rem){
		if (ret == 2){
			result1= c2<c1?start:end;
		}
		else if(ret == 3){ 
			result1 = c2>c1?start:end;
		}
	}
	else{
		result1 = start; 
	}
	return result1;
}
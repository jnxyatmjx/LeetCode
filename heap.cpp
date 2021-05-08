#include <stdio.h>
#include <math.h>
#include <algorithm> //std::max

//Use array and begin from 0

//Minimum Heap
template <typename T,typename INDX>
void heapifyUpToDown(T * li,INDX count,INDX position)
{
	INDX i,child;
	T tmp = li[position];
	for(i = position; 2*i+1 < count;i = child)
	{
		child = 2*i+1;
		if(2*i+2 < count && li[child] > li[2*i+2]) //find the smallest child 
			child++;

		if( li[child] < tmp)
			li[i] = li[child];
		else
			break;
	}
	li[i] = tmp;
}

template <typename INDEX,typename SIZE>
SIZE heapHeight(INDEX root,SIZE maxnum)
{
	if(root >= maxnum) return 0;
	
	return 1 + std::max( heapHeight(2*root + 1,maxnum),heapHeight(2*root+1,maxnum) );
}

template <typename T,typename INDX>
void heapPrintf(T* li,INDX count,char ** res)
{
	INDX heigh = heapHeight<INDX,INDX>(0,count);
	INDX width = (INDX)(::pow(2,heigh) - 1);
}


#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(int argc,char* argv[])
{	
	if (argc < 2) {printf("argc = 2 \n");return 0;}
	int n = atoi(argv[1]);	
	int * res = (int *)malloc(sizeof(int) * n); memset(res,0,sizeof(int)*n);
	
	srand(time(0)); 
	for(int i = 0; i< n;i++)
		res[i] = rand()%100; 
	
	//build heap
	for(int i = n/2 -1 ;i >= 0 ;i--)
		heapifyUpToDown<int,int>(res,n,i);

	printf("heap height:%d pow(2):%f\n",heapHeight<int,int>(0,n),::pow(2,3));
	
	for(int i = 0 ;i < n ;i++)
		printf("%d ",res[i]);	
		printf("\n");	

	return 0;
}

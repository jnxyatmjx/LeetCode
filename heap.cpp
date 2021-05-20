#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm> //std::max
#include <string> //std::string

//Use array and Begin from 0
//Minimum Heap

template <typename T,typename INDX>
void heapifyDownToUp(T* li,INDX count,INDX position)
{
	INDX i;
	T tmp = li[position];
	/*
	 * CAUTION : -1/2 = 0
	 * the purpose of (i-1)>=0 is redurce lost into busy loop
	 * */
	for(i = position; (i-1)>=0 && (i-1)/2 >= 0 && li[(i-1)/2] > tmp; i = (i-1)/2 )
		li[i] = li[(i-1)/2];
	li[i] = tmp;
}

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

template <typename T>
void heapSwap(T* a,T* b)
{
	T tp = *a;
	*a = *b;
	*b = tp;
}

template <typename T,typename INDX>
void heapSort(T * li,INDX count)
{
	//build heap
	for(INDX i = count/2 -1;i >=0;i--)
		heapifyUpToDown<T,INDX>(li,count,i);
	
	//swap and rebuild heap
	for(INDX i = count - 1;i > 0;i--)
	{
		heapSwap<T>(li + 0,li + i);
		heapifyUpToDown<T,INDX>(li,i,0);
	}
}

template <typename INDEX,typename SIZE>
SIZE heapHeight(INDEX root,SIZE maxnum)
{
	if(root >= maxnum) return 0;
	
	return 1 + std::max( heapHeight(2*root + 1,maxnum),heapHeight(2*root + 2,maxnum) );
}

template <typename T,typename INDX>
void heapPrintUpdate(INDX root,T* li,char *** res,INDX count,INDX row,INDX left,INDX right)
{
	if(root >= count) return;
	INDX mid = left + (right - left)/2;
	
	memcpy(res[row][mid],std::to_string( li[root] ).c_str(),2);

	heapPrintUpdate(2*root+1,li,res,count,row+1,left,mid - 1);
	heapPrintUpdate(2*root+2,li,res,count,row+1,mid + 1,right);
}
	
	
template <typename T,typename INDX>
void heapPrint(T* li,INDX count,char *** res)
{
	INDX heigh = heapHeight<INDX,INDX>(0,count);
	INDX width = (INDX)(::pow(2,heigh) - 1);
	heapPrintUpdate<T,INDX>(0,li,res,count,0,0,width-1);
}


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
int main(int argc,char* argv[])
{	
	if (argc < 2) {printf("argc = 2 \n");return 0;}
	int n = atoi(argv[1]);	
	int * res = (int *)malloc(sizeof(int) * n); memset(res,0,sizeof(int)*n);
	
	srand(time(0)); 
	for(int i = 0; i< n;i++)
		res[i] = rand()%100;

	//malloc res )))
	int row = heapHeight<int,int>(0,n);
	int colum = (int)::pow(2,row) - 1;
	char ***  ans = (char ***)malloc(sizeof(char**) * row);
	for(int i = 0 ;i < row;i++) ans[i] = (char**)malloc(sizeof(char*) * colum);
	
	//set value
	for(int i = 0;i < row;i++)
		for(int j = 0 ; j < colum;j++)
			{
				ans[i][j] = (char*)malloc(sizeof(char) * 2);
				memset(ans[i][j],' ',2);
			}	

	for(int i = 0 ;i < n ;i++)
		printf("%d ",res[i]);	
	
	printf("\n");
	
	//build heap
	for(int i = n/2 -1 ;i >= 0 ;i--)
		heapifyUpToDown<int,int>(res,n,i);
	heapPrint<int,int>(res,n,ans);
	
	heapSort<int,int>(res,n);
	printf("ufter sort:");
	for(int i = 0 ;i < n ;i++)
		printf("%d ",res[i]);	
	
	printf("\nPrint:\n");

	for(int i = 0;i < row;i++)
	{
		for(int j = 0 ; j < colum;j++)
			printf("%s",ans[i][j]);
		printf("\n");
	}

	printf("\n");

	//free resource
	for(int i = 0;i < row;i++)
		for(int j = 0 ; j < colum;j++)
			{
				free(ans[i][j]);
				ans[i][j] = NULL;
			}	

	return 0;
}

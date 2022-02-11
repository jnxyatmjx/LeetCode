#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <pthread.h>
#include <algorithm>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <poll.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <map>
#include <time.h>
#include <string>
#include <sys/time.h>

//merge sort This merge is stable
/*
 	Caution
	Merges two consecutive sorted ranges [first, middle) and [middle, last) into one sorted range [first, last).
	Result merged rangs NOT include the last one. 
*/
template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last); //merge [first,lst) ,so NOT middle+1..!!!
        std::inplace_merge(first, middle, last);
    }
}
 
//待排序数据分为已排序的前半部分 和 未排序的后半部分.取后半部分第一个元素插入到前半部分对应位置
template <typename T>
void insertsortPart(T *val,std::size_t left,std::size_t right){
	for(std::size_t i = left+1; i <= right ;i++){
		T temp = val[i];//获取未排序部分第一个元素
		for(size_t j = i; j > left && val[j] < val[j-1];j--){
			val[j] = val[j-1];
			val[j-1] = temp;
		}
	}
}

void insertSort(int *val ,size_t valen){
	for(size_t i = 1;i < valen ;i++){
		for(size_t j = i;j > 0 && val[j] < val[j-1];j--){
			int temp = val[j];
			val[j] = val[j-1];
			val[j-1] = temp;
		}
		for(size_t m = 0;m <= i ;m++)
		printf(" %d",val[m]);
	printf("\n");
	}
}

//待排序数据分为已排序的前半部分 和 未排序的后半部分.从后半部分找到合适数据 追加 到前半部分
void selectSortPart(int *val,size_t left,size_t right){
	for(size_t i = left ; i <= right;i++){
		size_t midex = i;
		for(size_t j=i+1;j <= right ;j++)
			if(val[j] < val[midex]) midex = j;
		int temp = val[i];
		val[i] = val[midex];
		val[midex] = temp;
	}
}

void selectSort(int * vecval,size_t veclen){
	for(size_t i = 0 ;i < veclen ;i++){
		size_t minIndex = i;
		for(size_t j = i+1;j < veclen;j++){
			if(vecval[minIndex] > vecval[j]){ minIndex = j;}
		}
		int temp = vecval[i];
		vecval[i] = vecval[minIndex];
		vecval[minIndex] = temp;
	}

}

//Binary search AS
template <typename T>
int binary_search(T *a,int l,int r,T targ)
{
	while(l <= r)
	{
		int m = l + (r - l)/2;
		if(*(a + m) == targ)
			return m;
		else if(*(a + m) > targ)
			r = m - 1; //if type is size_t, minus 1 maybe crash ! so type MUST contain negative value
		else if(*(a + m) < targ)
			l = m + 1;	
	}
	return -1;

}

//just for quick sort 
template <typename T>
void quicks_swap(T* a,T* b)
{
	T tem = *a;
	*a = *b;
	*b = tem;
}

//just for quick sort
template <typename T>
bool quicks_median3(T* a,std::size_t l,std::size_t r)
{	
	if( (r-l) < 2) return false; //the count of element must greate than 3
	std::size_t c = l + (r-l)/2;
	if(*(a+l) > *(a+c)) quicks_swap(a+l,a+c);
	if(*(a+l) > *(a+r)) quicks_swap(a+l,a+r);
	if(*(a+c) > *(a+r)) quicks_swap(a+c,a+r);

	quicks_swap(a+c,a+r-1);

	return true;
}

template <typename T>
void quicks(T* a,std::size_t l,std::size_t r,std::size_t cutoff = 11)
{
	if(l + cutoff <= r)
	{
		quicks_median3(a,l,r);
		T pivot = *(a+r-1);
		std::size_t i = l,j = r - 1;
		while(1)
		{
			while(a[++i] < pivot){} //STOP when element equal to pivot
			while(a[--j] > pivot){}
			if(i < j) quicks_swap(a+i,a+j);
			else break;
		}
		quicks_swap(a+i,a+r-1);
		quicks(a,l,i-1,cutoff);
		quicks(a,i+1,r,cutoff);
	}
	else
	{
		insertsortPart(a,l,r);	
	}	
}

#include <future>
//quick sort with multiple threads
template <typename T>
void quicks_mt(T* a,std::size_t l,std::size_t r,std::size_t cutoff = 11)
{
	if(l + cutoff <= r)
	{
		quicks_median3(a,l,r);
		T pivot = *(a+r-1);
		std::size_t i = l,j = r - 1;
		while(1)
		{
			while(a[++i] < pivot){} //STOP when element equal to pivot
			while(a[--j] > pivot){}
			if(i < j) quicks_swap(a+i,a+j);
			else break;
		}
		quicks_swap(a+i,a+r-1);
		auto lefts = std::async(std::launch::async,[&](){printf("Le->tid:%td\n",syscall(SYS_gettid));quicks_mt(a,l,i-1,cutoff);});
		auto rights = std::async(std::launch::async,[&](){printf("Ri->tid:%td\n",syscall(SYS_gettid));quicks(a,i+1,r,cutoff); });
	}
	else
	{
		insertsortPart(a,l,r);	
	}	
}


int main(int argc,char * argv[])
{
	(void)argc;
	int cpus = sysconf(_SC_NPROCESSORS_ONLN);printf("computers have %d cpus\n",cpus);

	srand(time(0)); printf("argv[1]:%d\n",atoi(argv[1]));
	int *a = (int*)malloc(sizeof(int) * atoi(argv[1]));memset(a,0,atoi(argv[1]));size_t a_len = atoi(argv[1]); 
	for(size_t i = 0; i< a_len;i++)
		a[i]=rand() ;
	printf("\n");

	//reverse(a,0,1);
	//selectSort(a,a_len);
	//selectSortPart(a,0,a_len-1);
	struct timeval now,cur;
	gettimeofday(&now,NULL);
	//quicks(a,0,a_len-1,13);
	printf("a Prev Poiter:%p <> %p\n",a,a+a_len-1);
	merge_sort(a,a+a_len);
	printf("a Post Poiter:%p <> %p\n",a,a+a_len-1);
	gettimeofday(&cur,NULL);
//	insertSortPart(a,0,a_len-1);
//	for(std::size_t i = 0;i < a_len;i++) printf("%d ",a[i]); 
	printf("MT Sort Complete (%td)\n", (cur.tv_usec - now.tv_usec)/1000 + (cur.tv_sec - now.tv_sec)*1000);

  while(1){	int compval;
		scanf("%d",&compval);
		printf("a len:%td\n",a_len);	
		int posi = binary_search<int>(a,0,(int)a_len - 1,compval);
		printf("posi:%d\n",posi);
	}


poll(NULL,0,-1);
return 0;
}

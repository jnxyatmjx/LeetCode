#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sched.h>
#include <pthread.h>

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
//待排序数据分为已排序的前半部分 和 未排序的后半部分.取后半部分第一个元素插入到前半部分对应位置
void insertSortPart(int *val,size_t left,size_t right){

	for(size_t i = left+1; i <= right ;i++){
		int temp = val[i];//获取未排序部分第一个元素
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
		for(int m = 0;m <= i ;m++)
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

void delChar(char * buf,char delval){
	if (buf == NULL) return;
	char * fast,*slow;
	fast = slow = buf;
	while(*fast != '\0')
	{
		if( *fast != delval)
		{
			*slow = *fast;
			slow++;
		}
		fast++;
	}
	while(slow != fast){*slow = '\0';slow++;}	

}

void reverse(int *a,int left,int right)
{
	if(left < right)
	{
		int temp;
		temp = *(a+left);
		*(a+left) = *(a+right);
		*(a+right) = temp;	
		reverse(a,left+1,right-1);
	}
}
void * thuc(void * index){
	cpu_set_t cpuMask;
 	intptr_t i = (intptr_t)index; //in 64-bit system (void *) have 8Bytes but (int) only have 4Bytes!!!
	CPU_ZERO(&cpuMask);
	CPU_SET(i,&cpuMask);
	pthread_setaffinity_np(pthread_self(), sizeof(cpuMask), &cpuMask);

   	sleep(1);
	pthread_exit(NULL);
}

int main()
{

	int cpus = sysconf(_SC_NPROCESSORS_ONLN);printf("computers have %d cpus\n",cpus);

	srand(time(0));
	int a[5]= {0};size_t a_len = sizeof(a)/sizeof(a[0]);
	for(size_t i = 0; i< a_len;i++)
		a[i]=rand()/100000;
	for(size_t i = 0;i < a_len;i++)
		printf("%d ",*(a+i));
	printf("\n");

	//reverse(a,0,1);
	//selectSort(a,a_len);
	selectSortPart(a,0,a_len-1);
	//insertSort(a,a_len);
//	insertSortPart(a,0,a_len-1);
	for(size_t i = 0;i < a_len;i++)
		printf("%d ",*(a+i));
	printf("\n");


	char * bufd = new char[100];memset(bufd,0,100);
	//snprintf(bufd,100,"%s","ggggggggggggabcdefgggg");
	delChar(bufd,'g');	
	delete []bufd;


poll(NULL,0,-1);
return 0;
}

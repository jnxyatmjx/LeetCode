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

void * thuc(void * index){
	cpu_set_t cpuMask;
 	intptr_t i = (intptr_t)index; //in 64-bit system (void *) have 8Bytes but (int) only have 4Bytes!!!
	CPU_ZERO(&cpuMask);
	CPU_SET(i,&cpuMask);
	pthread_setaffinity_np(pthread_self(), sizeof(cpuMask), &cpuMask);

   	sleep(1);
	pthread_exit(NULL);
}

int main(int argc,char * argv[])
{

	int cpus = sysconf(_SC_NPROCESSORS_ONLN);printf("computers have %d cpus\n",cpus);

	srand(time(0)); printf("argv[1]:%d\n",atoi(argv[1]));
	int *a = (int*)malloc(sizeof(int) * atoi(argv[1]));memset(a,0,atoi(argv[1]));size_t a_len = atoi(argv[1]); 
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
		
  while(1){	int compval;
		scanf("%d",&compval);
		printf("a len:%td\n",a_len);	
		int posi = binary_search<int>(a,0,(int)a_len - 1,compval);
		printf("posi:%d\n",posi);
	}
	char * bufd = new char[100];memset(bufd,0,100);
	//snprintf(bufd,100,"%s","ggggggggggggabcdefgggg");
	delChar(bufd,'g');	
	delete []bufd;


poll(NULL,0,-1);
return 0;
}

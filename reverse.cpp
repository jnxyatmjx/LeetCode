#include <stdio.h>
#include <string.h>
#include <string>

// reverse recurision
template <typename T,typename S>
void reverse_recu(T * a,S left,S right)
{ 	
	if(a == NULL) return;
	
	if(left < right)
	{
		T temp;
		temp = *(a+left);
		*(a+left) = *(a+right);
		*(a+right) = temp;	
		reverse_recu(a,left + 1,right - 1);
	}
}

template <typename T,typename S>
void reverse_while(T* val,S left,S right)
{
	if(val == NULL) return ;
	while(left < right)
	{
	 	T tval;
		tval = *(val + left);
		*(val + left) = *(val + right);
		*(val + right) = tval;	
		left++;
		right--;
	}

}

int main(int argc,char * argv[])
{
	printf("%s argv[1] size:%td\n",argv[1],::strlen(argv[1]));
//	reverse_while<char,size_t>((char *)val.c_str(),(size_t)0,::strlen(val.c_str())   -   1);
	reverse_recu<char,size_t>(argv[1],(size_t)0,::strlen(argv[1])   -   1);
	printf("%s argv[1] size:%td\n",argv[1],::strlen(argv[1]));
	
	return 0;
}

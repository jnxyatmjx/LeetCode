#include <stdio.h>
#include <string.h>
#include <string>

template <typename T>
void reverse_swap(T* l,T* r)
{
	T tval = *l;
	*l = *r;
	*r = tval;
}

// reverse recurision
template <typename T,typename S>
void reverse_recu(T * a,S left,S right)
{ 	
	if(a == NULL || a[right] == '\0') return;
	
	if(left < right)
	{
		reverse_swap(a + left,a + right);
		reverse_recu(a,left + 1,right - 1);
	}
}


//reverse two pointers
template <typename T,typename S>
void reverse_while(T* val,S left,S right)
{
	if(val == NULL || val[right] == '\0') return ;
	while(left < right)
	{	
		reverse_swap(val + left,val + right);
		left++;
		right--;
	}

}

int main(int argc,char * argv[])
{	(void)argc;
	printf("%s argv[1] size:%td\n",argv[1],::strlen(argv[1]));
	
//	reverse_while<char,size_t>(argv[1],(size_t)0,::strlen(argv[1])   -   1);
	reverse_recu<char,size_t> (argv[1],(size_t)0,::strlen(argv[1])   -   1);
	
	printf("%s argv[1] size:%td\n",argv[1],::strlen(argv[1]));
	
	return 0;
}

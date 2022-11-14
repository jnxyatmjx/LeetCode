#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

namespace pattern{

namespace s1{
template<typename T>
class Singleton{
private:
		Singleton() = delete;
		~Singleton() = delete;
public:
		static T& instance(){
			pthread_once(&once_,&Singleton<T>::init);
			return *insta_;
		}
private:
		static void init(){
			insta_ = new T();
		}

private:
	static T* insta_;
	static pthread_once_t once_;
};

template<typename T>
T* Singleton<T>::insta_ = NULL;

template<typename T>
pthread_once_t Singleton<T>::once_ = PTHREAD_ONCE_INIT;
}//end namespace s1

//Lazy Construct
namespace s2{
template<typename T>
class Singleton{
public:
	Singleton() = delete;
	~Singleton() = delete;
public:
	static T& instance(){
		if(inst_ == NULL)
		{
			inst_ = new T();
		}
		return *inst_;
	}
private:
	static T * inst_;
private:
	class Delter { //Destruct the instance
		public:
			~Delter(){
				if(Singleton::inst_ != NULL)
					delete Singleton::inst_;
				printf("Real heaer?\n");
			}
	};//end class Delter
	static Delter delt_;
};

template<typename T>
T* Singleton<T>::inst_ = NULL;
}//end namespace s2

namespace s3{
	template <typename T>
	class Singleton
	{
	public:
		static T& instance(){
			static T inst_; //after C++11 Compiler guarantees the 'Local Static Variable' is ThreadSafe
			return inst_;
		}
	public:
		Singleton() = delete;
		~Singleton() = delete;
	};
}//end namespace s3

} //end namespace

using namespace pattern;
#include <thread>
#include <chrono>

using MonotonicTime = std::chrono::time_point<std::chrono::steady_clock>;

class demo{
	public:
	demo(){printf("construct demo %p %d\n",this,i);}
	~demo(){printf("destruct demo %d %p\n",i,this);}
	public:
		int set(int a){i = a;}
		int get(){return i;}
	private:
		int i;
};

#define KKSD 1000*1000*2UL
int main(int argc, char* argv[]){
	std::thread a1([](){
		s1::Singleton<demo>::instance().set(1);
		MonotonicTime beg = std::chrono::steady_clock::now();
		for(long i=0; i<KKSD; i++){
				s1::Singleton<demo>::instance();
		}
		MonotonicTime endg = std::chrono::steady_clock::now();
		printf("s1 eslaps :%.3f\n",std::chrono::duration<double>(endg - beg).count());
			});
			
	std::thread a2([](){
		s2::Singleton<demo>::instance().set(2);
		MonotonicTime beg = std::chrono::steady_clock::now();
		for(long i=0; i<KKSD; i++){
				s2::Singleton<demo>::instance();
		}
		MonotonicTime endg = std::chrono::steady_clock::now();
		printf("s2 eslaps :%.3f\n",std::chrono::duration<double>(endg - beg).count());
			});

	std::thread a3([](){
		s3::Singleton<demo>::instance().set(3);
		MonotonicTime beg = std::chrono::steady_clock::now();
		for(long i=0; i<KKSD; i++){
			s3::Singleton<demo>::instance();
		}
		MonotonicTime endg = std::chrono::steady_clock::now();
		printf("s3 eslaps :%.3f\n",std::chrono::duration<double>(endg - beg).count());
			});


	a3.join();
	a2.join();
	a1.join();
printf("s3 :%d \n",s3::Singleton<demo>::instance().get());
	return 0;
}


//#if defined(WINDOWS_64) || defined(WINDOWS_32)
#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <assert.h>

namespace lrucache{

	template<typename T>
	class delist
	{
		typedef struct lNode
		{
			T val;
			struct lNode* prev;
			struct lNode* next;
		}lNode;

	public:
		explicit delist(size_t max_size)
			:head_(NULL), capacity_(max_size), num_(0)
		{}

		~delist()
		{
			while(head_)
			{
				rm1node(head_);
			}
		}

		void add2head(T val)
		{
			lNode* tmp = this->mallocNode();
			tmp->val = val;

			tmp->next = head_;
			if (head_) head_->prev = tmp;
			head_ = tmp;

			num_++;
		}

		T rm1node(lNode* pnode)
		{
			assert(pnode != NULL && num_ > 0);
			T res = pnode->val;

			if (pnode->prev){
				(pnode->prev)->next = pnode->next;
			}
			else{
				head_ = pnode->next;
			}

			if (pnode->next){
				(pnode->next)->prev = pnode->prev;
			}
			num_--;

			//release resource
			//pnode->next = NULL; //ERROR
			//pnode->prev = NULL; //ERROR
			this->freeNode(pnode);


			return std::move(res);
		}


	private:
		inline lNode* mallocNode()
		{
			return (lNode*)calloc(1, sizeof(lNode));
		}

		inline void freeNode(lNode* pn_)
		{
			if (pn_)
			{
				pn_->next = NULL;
				pn_->prev = NULL;
				::free(pn_);
				pn_ = NULL;
			}
		}
	private:
		lNode* head_;
		size_t capacity_;
		size_t num_;
	};
	class cache{
		cache()
		{}

		~cache()
		{}
	};

}//end namespace
int main(int argc,char* argv[])
{
	{
		lrucache::delist<int> dli(19);
		dli.add2head(1);
		dli.add2head(2);
		dli.add2head(3);
		dli.add2head(4);
		dli.add2head(5);
	}
	getchar();
	return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <list>

// a binary tree Encode and Decode
namespace EncodeDecode{

    template <typename T>
    struct tNode
    {
        T val;
        struct tNode * left;        
        struct tNode * right;
        
	tNode():left(NULL),right(NULL){}

        tNode(const T& v):left(NULL),right(NULL)
        {
		val = v;
        }        
    };

    template<typename T>
    class treeED
    {
    private:
        tNode<T> * createNode(T val)
        {
            tNode<T> * nod = (tNode<T>*)malloc(sizeof(tNode<T>));
            nod->val = val;
	    return nod;
        }

        void freeNode(tNode<T> *nod)
        {
            if(nod) free(nod);
            nod = NULL;
            //nod->left = NULL;
            //nod->right = NULL;
        }
    
        /*
            # --> is a NULL pointer
            , --> is separator of 2 poiners

        */
        void EncodeInorder(tNode<T>* root,std::string& res)
        {
            if(root == NULL)
	    {
		    res.append("#,");
		    return;
	    }

	    res.append(std::to_string(root->val)).append(",");

	    EncodeInorder(root->left,res);
	    EncodeInorder(root->right,res);
        }

	tNode<T> * DecodeInorder(std::list<std::string>& list)
	{
		if(list.empty()) return NULL;

		std::string valss = std::move(list.front());list.pop_front();
		if(valss.compare("#") == 0 ) return NULL;	

		tNode<T>* node = createNode(atoi(valss.c_str()));
		printf("sub i %p\n",node);
		node->left = DecodeInorder(list);
		node->right = DecodeInorder(list);
		return node;
	}

public:	
	/*
            # --> is a NULL pointer
            , --> is separator of 2 poiners
        */

	std::string Encode(tNode<T>* root)
	{
		std::string res;

		EncodeInorder(root,res);

		return std::move(res);
	}
	
	tNode<T> * Decode(const std::string& ress)
	{
		std::list<std::string> clist_;	
		
		std::size_t slen = ress.length();
		for(std::size_t i=0,j=0; i<slen && j<slen; j++)
		{
		    if(ress.at(j) == ',')
		    {
			clist_.push_back(ress.substr(i,j-i));
			i = j+1;
		    }
		}

	for(const auto& m: clist_)		
	printf("%s ",m.c_str());	printf("\n");
		
		return DecodeInorder(clist_);
	}//end Decode

        treeED()
        {}

        ~treeED()
        {}

    }; //end class
    

}//end namespace

int main(int argc,char * argv[])
{
	EncodeDecode::treeED<int> ed;
	
	EncodeDecode::tNode<int> * root = ed.Decode("-3,1,15,#,#,1029,#,#,#,");    
	printf("%p\n",root);	
	
return EXIT_SUCCESS;
}

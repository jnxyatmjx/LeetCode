
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <math.h>
#include <deque>

template <typename T>
    struct tNode
    {
        T val;
        struct tNode * left;        
        struct tNode * right;
        
	    tNode():left(NULL),right(NULL){}

        tNode(const T& v):left(NULL),right(NULL),val(v)
        {}        
    };


//tree
namespace tree{

#define maxl(a,b)\
	({ __typeof__ (a) a_ = (a);\
	 __typeof__ (b) b_ = (b);\
	 a_ > b_ ? a_ : b_;})

#define minl(a,b)\
	({ __typeof__ (a) a_ = (a);\
	 __typeof__ (b) b_ = (b);\
	 a_ < b_ ? a_ : b_;})


	template<typename T>
	std::size_t binaryTreeMaxHeigh(tNode<T> *root)
	{
		if(root == NULL) return 0;
		return 1 + std::max( binaryTreeMaxHeigh(root->left) , binaryTreeMaxHeigh(root->right) );
	}
	
    template<typename T>
	void binaryTreePher(tNode<T> * root,std::vector<std::vector<std::string>>& res,std::size_t row,std::size_t lef,std::size_t rig)
	{
        if(root == NULL) return ;

        std::size_t mid = lef + (rig - lef) /2;
        res[row][mid]  = std::to_string(root->val);

        binaryTreePher(root->left,res,row+1,lef,mid-1);
        binaryTreePher(root->right,res,row+1,mid+1,rig);
	}

	template<typename T>
	void binaryTreePrint(tNode<T> * root)
	{
        std::size_t row = binaryTreeMaxHeigh(root);
        std::size_t colum = ::pow(2,row) - 1;
        
        std::vector<std::vector<std::string> > res(row, std::vector<std::string>(colum,"-|-") );
        
        binaryTreePher(root,res,0,0,colum-1);

        for(const auto& ii: res)
        {
            for(const auto& jj: ii)
            {
                printf("%s",jj.c_str());
            }
            printf("\n");
        }

	}

    template<typename T>
    void binaryTreePrintPreorder(tNode<T> * root)
    {
        if(root == NULL) return ;
        printf("%d ",root->val);

        binaryTreePrintPreorder(root->left);
        binaryTreePrintPreorder(root->right);
    }
} 

// a binary tree Encode and Decode
namespace EncodeDecode{

    template<typename T>
    class BinaryTreeED
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
    void EncodePreorder(tNode<T>* root,std::string& res)
    {
        if(root == NULL)
        {
            res.append("#,");
            return;
        }

        res.append(std::to_string(root->val)).append(",");

        EncodePreorder(root->left,res);
        EncodePreorder(root->right,res);
    }

	tNode<T> * DecodePreorder(std::list<std::string>& list)
	{
		if(list.empty()) return NULL;

		std::string valss = std::move(list.front());list.pop_front();
		if(valss.compare("#") == 0 ) return NULL;	

		tNode<T>* node = createNode(atoi(valss.c_str()));
		
		node->left = DecodePreorder(list);
		node->right = DecodePreorder(list);
		return node;
	}
    /*
        curlev  : current level of binary three
    */
    void levelDfs(std::vector<std::string>& res,int curlev,tNode<T> *root)
    {
        if(res.size() <= curlev) //current level of this tree is greater than vector(res) 's size
            res.push_back( std::string("") );
        
        if(root == NULL)
        {
            res[curlev].append(std::string("#,"));
            return ;
        }

        res[curlev].append( std::to_string(root->val) + "," );

        levelDfs(res, curlev + 1 ,root->left);  //++curlev or curlev++ are all ERROR
        levelDfs(res, curlev + 1 ,root->right);
    }

    void encodeLevel(tNode<T> *root,std::string& res_ss)
    {
        std::vector<std::string> level_evc;
        levelDfs(level_evc,0,root);
        
        for(const auto& m_le : level_evc)
        {
            res_ss.append(m_le);
        }

    }

    tNode<T> * decodeLevel(std::list<std::string>& list_)
    {
        std::string valss = std::move(list_.front());list_.pop_front();
        if(valss.compare("#") == 0) return NULL;

        tNode<T>* root = createNode(atoi(valss.c_str()));
        std::deque<tNode<T>*> q_; q_.push_back(root);

        // while(!q_.empty())
        // {
            while( !list_.empty() )
            {
                tNode<T>* parent = q_.front();q_.pop_front();

                std::string valTmp = std::move(list_.front());list_.pop_front();
                if(valTmp.compare("#") != 0)
                {
                    parent->left = createNode(atoi(valTmp.c_str()));
                    q_.push_back(parent->left);
                }else
                    parent->left = NULL;

                
                valTmp = std::move(list_.front());list_.pop_front();
                if(valTmp.compare("#") != 0)
                {
                    parent->right = createNode(atoi(valTmp.c_str()));
                    q_.push_back(parent->right);
                }else
                    parent->right = NULL;
            }
        //}

        return root;
    }


public:	
	    /*
            # --> is a NULL pointer
            , --> is separator of 2 poiners
        */

	std::string Encode(tNode<T>* root)
	{
		std::string res;

		//EncodePreorder(root,res);
        encodeLevel(root,res);
		return res; //RVO?
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
		printf("%s ",m.c_str());	
	printf("\n");
		
		//return DecodePreorder(clist_);
        return decodeLevel(clist_);
	}//end Decode

        BinaryTreeED()
        {}

        ~BinaryTreeED()
        {}

    }; //end class
    

}//end namespace

int main(int argc,char * argv[])
{
	EncodeDecode::BinaryTreeED<int> ed;
	
	//tNode<int> * root = ed.Decode("-3,1,15,#,#,-10,#,#,#,");
	tNode<int> * root = ed.Decode("-3,1,#,15,-10,#,#,#,#,");
    printf("-3,1,#,15,-10,#,#,#,#,\n");


// tNode<int> * root = (tNode<int>*)malloc(sizeof(tNode<int>));root->val = -3;// new tNode<int>(-3);
// tNode<int> * r1 = (tNode<int>*)malloc(sizeof(tNode<int>)); r1->val = 1;
// tNode<int> * r15 = (tNode<int>*)malloc(sizeof(tNode<int>)); r15->val = 15;
// tNode<int> * r10 = (tNode<int>*)malloc(sizeof(tNode<int>)); r10->val = -10;
// r15->left = r10;
// root->left = r1; root->right = r15;

    std::string ssd = ed.Encode(root);
    printf("after %s\n",ssd.c_str());

    //tree::binaryTreePrintPreorder(root);
    //printf("\n");
	//EncodeDecode::tNode<int> * root = ed.Decode("-3,1,15,#,#,1029,#,#,#,");    
	tree::binaryTreePrint(root);
	
return EXIT_SUCCESS;
}

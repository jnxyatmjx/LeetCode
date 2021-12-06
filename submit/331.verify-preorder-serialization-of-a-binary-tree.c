/*
 * @lc app=leetcode id=331 lang=c
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start

//capacity_ means characters in preorder,
//add a not-null node into tree means-->
//character in preorder minus 1..  and we obtain two more leaves in the tree and capacity_+= 2.

bool isValidSerialization(char * preorder){
    
    char* order_vc = (char*)calloc(strlen(preorder)+2,sizeof(char));
    strncpy(order_vc,preorder,strlen(preorder));
    order_vc[strlen(preorder)] = ',';//add comma
    
    size_t ve_le = strlen(order_vc);
    int capacity_ = 1;//tree must have a root
    for(size_t i=0; i<ve_le; i++)
    {
        if(order_vc[i] != ',') continue;
        if(--capacity_ < 0) return false;
        if(order_vc[i-1] != '#') capacity_+=2;
    }

    return capacity_ == 0;
}

#if 0
//caution if value have more than one char symbol
//"9,#,92,#,#"\n
//"92,#,#,21"\n
int orderNum(char* pre)
{   
    int count = 0;
    char* cur = pre;
    while ( *cur != 0)
    {
        if(*cur == ',') count++;
        cur++;
    }
    return count+1;
}

void ordersplit(char* preorder,char** ordervec)
{
    char* cur = preorder;
    int idx1=0, idx2=0;
    
    while(*cur != 0)
    {
        if(*cur != ',')
        {
            ordervec[idx1][idx2]=*cur;
            idx2++;
        }else{
            idx2 = 0;
            idx1++;
        }
        cur++;
    }
}

void preorder_build(char** ordervec,int* idx,int orderLen,bool* isValid)
{
    if(*idx >= orderLen) //error
    {
        *isValid = false;
        return ;
    }

    if (strcmp(ordervec[*idx],"#") == 0 )
    {
        *idx += 1;
        return;
    }

    *idx += 1;

    preorder_build(ordervec,idx,orderLen,isValid);
    preorder_build(ordervec,idx,orderLen,isValid);
}

//"9,3,4,#,#,1,#,#,2,#,6,#,#"
//"9,#,#,1"\n
bool isValidSerialization(char * preorder){
    
    int orderLen = orderNum(preorder);

    char ** ordervec = (char**)calloc(orderLen+1,sizeof(char*));
    for(int i=0; i<orderLen; i++)
        ordervec[i] = (char*)calloc(4,sizeof(char));
    
    ordersplit(preorder,ordervec);

    int idx = 0;
    bool isVald = true;
    preorder_build(ordervec,&idx,orderLen,&isVald);
    
    if(idx < orderLen)  //if preorder recursive is over e.g. (9,#,#,1). but ordervec still have values
        isVald = false;

    return isVald;
}

#endif
// @lc code=end


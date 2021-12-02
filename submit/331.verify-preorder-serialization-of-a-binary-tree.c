/*
 * @lc app=leetcode id=331 lang=c
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
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
// @lc code=end


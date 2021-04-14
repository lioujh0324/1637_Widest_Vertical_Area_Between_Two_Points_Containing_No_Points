void Swap(int **start, int a,int b);
void QuickSort(int **start,int left,int right,int numsSize);

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize)
{
    int max=0,i=1;
    QuickSort(points,1,pointsSize,pointsSize);
    while(i<pointsSize)
    {
        if(**(points+i)-**(points+i-1)>max)
            max=**(points+i)-**(points+i-1);
        i++;
    }
    return max;
}
void Swap(int **start, int a,int b)
{
    int temp;
    temp=**(start+a-1);
    **(start+a-1)=**(start+b-1);
    **(start+b-1)=temp;
}
void QuickSort(int **start,int left,int right,int numsSize)
{
    int pivot=left;
    int i=left+1, j=right+1;
    
    while(i<j)
    {
        while(**(start+i-1)<=**(start+pivot-1) && i<=numsSize-1)
            i++;
        j--;
        while(**(start+j-1)>**(start+pivot-1))
            j--;
        if(i<j)
        {
            Swap(start,i,j);
        }
        else
        {
            Swap(start,pivot,j);
            QuickSort(start,left,j-1,numsSize);
            QuickSort(start,j+1,right,numsSize);
        }
    }

}

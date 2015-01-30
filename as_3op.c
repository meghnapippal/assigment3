#include<stdio.h>
#include<stdlib.h>
int * compare(int *,int , int , int * ,int *,int );
int check(int , int *, int *);
void main()
{
    int *qtr/*!< This pointer is used to store values of "b" */,h,i,*tr,*tr2,*qtr2,r,q,*v,*v2,k,*ptr,*ptr2,sum;
    int a1,r1,n,ra,r2,q3,r3;
    ra=0;
    printf("Enter the value of k and sets in file:\n");
    FILE *input;
    input = fopen ("input.txt","r");
    i=0;
    while(!feof(input))
    {
        fscanf(input, "%d," ,&ra);
        i++;
    }
    n=i-1;
    ptr=(int *)malloc(n*sizeof(int));
    FILE *inputr;
    inputr = fopen ("input.txt","r");
    while(!feof(inputr))
    {
        fscanf(inputr, "%d," ,ptr);
        ptr++;
    }
    ptr2=ptr-1;
    ptr=ptr-i;
    i=0;
    while(ptr<ptr2)
    {
        ptr++;
        i++;
    }
    ptr=ptr-i;
    ra=0;
    tr=(int*)malloc((n-2)*sizeof(int));
    qtr=(int*)malloc((n-3)*sizeof(int));
    v=(int*)malloc((n-4)*sizeof(int));
    printf("All possible subsets are:\n");
    r1=0;
    for(h=1; h<n; h++)
    {
        a1=1;
        for(i=1; i<=r1; i++)
        {
            if(*(ptr+h) == *(ptr+h-i) )
            {
                a1=0;
                break;
            }
        }

        if(a1==1)
        {
            tr2=compare(tr,n,h,NULL,NULL,1);
            r=0;
            while(tr<tr2)
            {
                q= check(r,tr,ptr);
                if(q==1)
                {
                    qtr2=compare(qtr,n,h,tr,NULL,2);
                    r2=0;
                    while(qtr<qtr2)
                    {   
                        q=check(r2,qtr,ptr);
                        if(q==1)
                        {
                            v2=compare(v,n,h,tr,qtr,3);
                            r3=0;
                            while(v<v2)
                            {
                                q3=check(r3,v,ptr);
                                if(q3==1)
                                {
                                    sum=(*(ptr+h))+(*(ptr+(*tr)))+(*(ptr+(*qtr)))*(*(ptr+(*v)));
                                    if(sum <= *(ptr))
                                    {
                                        printf("a:%d b:%d c:%d d:%d\n",*(ptr+h),*(ptr+(*tr)),*(ptr+(*qtr)),*(ptr+(*v)));
                                        ra++;
                                    }
                                }
                                v++;
                                r3++;
                            }
                            v=v-r3;
                        }
                        qtr++;
                        r2++;
                    }
                    qtr=qtr-r2;
                }
                tr++;
                r++;
            }
            tr=tr-r;
        }
        r1++;
    }
    printf("no: %d",ra);
}

int check(int r, int *ptr , int *t)
{
    int l,a;
    a=1;
    for(l=1; l<=r; l++)
    {
        if(*(t+(*ptr)) == *(t+(*(ptr-l))) )
        {
            a=0;
            break;
        }
    }
    return a;

}

int * compare(int *lo,int n, int h, int *tr ,int *qtr,int y)
{
    int i;
    for(i=1; i<n; i++)
    {
        if(y==1)
        {
            if(h!=i)
            {
                *lo=i;
                lo++;
            }
        }
        if(y==2)
        {
            if(i!=h && i!=(*tr) )
            {
                *lo=i;
                lo++;
            }
        }
        if(y==3)
        {
            if(i!=h && i!=(*tr) && i!=(*qtr) )
            {
                *lo=i;
                lo++;
            }
        }
    }
    return lo;
}

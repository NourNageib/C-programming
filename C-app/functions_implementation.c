#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "functions_include.h"

void ScanSring(char*str)
{
    int i=0;
    fflush(stdin);

    while(str[i-1] != '\n')
    {

      scanf("%c",str+i);
      i++;
    }
    str[i]='\0';
}

int  StringLength(char*str)
{
    int c=0;
    while(str[c])
    {
        c++;
    }
    return c;
}
int VowelsCount(char *str)
{
    int c=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i'|| str[i]=='o' || str[i]=='u' )
            c++;
    }

    return c;
}
void PrintAlphabets(char*str)
{
    for(int i=0;str[i];i++)
    {
        if(str[i]>= 'A' && str[i]<='Z')
        {
            printf("%c",str[i]);
        }
        else if(str[i]>= 'a' && str[i]<='z')
        {
            printf("%c",str[i]);
        }
    }
    printf("\n");

}
void Cars(void)
{
    int i=0,num_Car;
     printf("Enter number of cars you want to enter its data:\n");
     scanf("%d",&num_Car);
     Car * Cars = malloc(num_Car*sizeof(Car));
     for(i=0;i<num_Car;i++)
     {
         ScanCarData(&Cars[i]);

     }
     printf("Enter car ID To calculate rental cost:\n");
     scanf("%d",&i);
     CarRentalCost(Cars[i]);

}
void PrintCarData(Car * DisplayCarData)
{
    printf("Car ID :%d\n",DisplayCarData->CarID);
    printf("Car Rental Rate :%f\n",DisplayCarData->rentalRate);
    printf("Car modal :%s\n",DisplayCarData->modal);
}
void ScanCarData(Car *inputCarData)
{
     char string[100];
     printf("Please enter Car Data :\n");
     printf("Enter Car ID:\n");
     scanf("%d",&(inputCarData->CarID));
     printf("Enter rentalRate : \n");
     scanf("%f",&(inputCarData->rentalRate));
     while (getchar() != '\n');
     printf("Enter Car model : \n");
     gets(inputCarData->modal);
     PrintCarData(inputCarData);
}
void CarRentalCost(Car CarData)
{
    int days ;
    printf("How many days you want to rent the car?\n");
    scanf("%d",&days);
    printf("Rental cost for Car model : %s is %d.\n",CarData.modal,days*(CarData.rentalRate));

}
void multiplicable_by_5(void)
{
    int n;
     printf("Please enter number to check if it multiples of 5 :\n");
     scanf("%d",&n);
     printf("%s\n",n%5?" Num is not multiple of 5" : "Num is  multiple of 5");

}
void lengthofstring(char*string)
{
     printf("%s",string);
     int x=StringLength(string);
     printf("Length : %d\n",x);
}
void Vowelcount(char *str)
{
    int v=VowelsCount(str);
     printf("Num of vowels : %d\n",v);

}

void Scan2DArray(int (*arr)[100],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

}
void Print2DArray(int (*arr)[100],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        printf("[");
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("]\n");
    }


}
void compare_2D_Array(void)
{

    int arr1[100][56],arr2[100][56];
    int row1,row2,col1,col2,flag=0;
    printf("Please enter number of rows of array1:\n");
    scanf("%d",&row1);
    printf("Please enter number of coloum of array1:\n");
    scanf("%d",&col1);
    printf("Enter array 1 elements :\n");
    Scan2DArray(arr1,row1,col1);
    printf("Please enter number of rows of array2:\n");
    scanf("%d",&row2);
    printf("Please enter number of coloum of array2:\n");
    scanf("%d",&col2);
    printf("Enter array 2 elements :\n");
    Scan2DArray(arr2,row2,col2);
    printf("Array 1:\n");
    Print2DArray(arr1,row1,col1);
    printf("Array 2:\n");
    Print2DArray(arr2,row2,col2);
    if((row1==row2)&&(col1==col2))
    {
        for(int i=0;(flag==0)&&(i<row1);i++)
        {
            for(int j=0;(flag==0)&&(j<col1);j++)
            {
                if(arr1[i][j] != arr2[i][j])
                {
                    flag=1;
                }
            }
        }
        if(flag)
        {
             printf("Array 1 ISNOT EQUAL to Array 2.\n");
        }
        else
        {
             printf("Array 1 is EQUAL to Array 2.\n");
        }
    }
    else
    {
        printf("Array 1 ISNOT EQUAL to Array 2.\n");
    }
}
void ScanArray(int*arr,int length)
{
    for (int i=0;i<length;i++)
    {
        scanf("%d",arr+i);
    }
}
void PrintArray(int*arr,int length)
{
    printf("[");
    for (int i=0;i<length;i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("]\n");
}
int FindMax(int *arr,int length,int *index)
{
    int max=0;
    for (int i=0;i<length;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            *index=i;
        }
    }
    return max;

}
void PrintUniqueElements(void)
{
    int arr[20],num,in;
    printf("Enter number of elements of array :\n");
    scanf("%d",&num);
    ScanArray(&arr,num);
    PrintArray(&arr,num);
    int max=FindMax(arr,num,&in);
    int*freqarray=calloc(max,sizeof(int));
    for(int i=0;i<=max;i++)
    {
        freqarray[arr[i]]++;
    }
    printf("Unique elements of the array:\n");
    printf("[");
    for(int i=0;i<=max;i++)
    {

        if(freqarray[i]==1)
        {
            printf("%d ",i);
        }
    }
    printf("]\n");
}
int onescount_2Darray(int (*arr)[4],int row ,int col)
{
    int c =0,max=0,index=0;
    for(int i=0;i<row;i++)
    {
        c=0;
        for(int j=0;j<col;j++)
        {
            if(arr[i][j]==1)
            {
                c++;

            }

        }
        //printf("%d   %d\n",c,max);
        if(c>max)
        {
                index=i;
                max=c;
        }

    }
    return index;
}
void ones_rowCounter(void)
{
    int arr[4][4]={{1,0,0,1},
                    {1,1,1,1},
                    {1,0,0,0},
                    {1,1,0,1},
                    };

    int row=onescount_2Darray(arr,4,4);
    printf("row with max 1s is :%d",row);
}
void findindex(int (*arr)[4],int row,int col,int key)
{
    int flag=1,c_ind,i,j;
    for(i=0;flag&&(i<row);i++)
    {

        for( j=0;flag&&(j<col);j++)
        {
            if(arr[i][j]==key)
            {

                flag=0;
            }
        }
    }
    if(flag==1)
    {
        printf("Number isn't found \n");
    }
    else
    {
            printf("Key found at index : row no.:%d, coloumn no.:%d.\n",i,j);
    }


}
void swap(int*a,int*b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}
void BubbleSort(int *arr,int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void Search2Darray(void)
{
    int arr[4][4]={ {1,34,2,12},
                    {2,3,14,30},
                    {33,44,12,90},
                    {112,98,47,133},
                    };

    findindex(arr,4,4,112);
}
void Sepreate0s_1s(void)
{
    int arr [12]={1,0,1,1,0,0,1,0,1,1,1,0};
    BubbleSort(arr,12);
    PrintArray(arr,12);
}
void RearrangeArray(int * arr,int length)
{
    int max=arr[0],min=arr[0],index=0,flag=0;
    for(int i=0;i<length;i++)
    {
        flag=0;max=arr[i];min=arr[i];
      for(int j=i;j<length;j++)
        {

            if((i%2))
            {
               if(arr[j]>max)
               {
                   max=arr[j];
                   index=j;
                   flag=1;
               }

            }
            else if (!(i%2))
            {
                       if(arr[j]<min)
                       {
                           min=arr[j];
                           index=j;
                           flag=1;
                       }

            }
        }
        if(flag)
        swap(&arr[i],&arr[index]);
        //PrintArray(arr,length);

    }
}
void zigzagArrangment(void)
{
    int arr[9]={5 ,8 ,1 ,4 ,2 ,9 ,3 ,7 ,6};
    RearrangeArray(arr,9);
    PrintArray(arr,9);
}
void CopyArray(int *arr,int *arr2,int length)
{
    for(int i=0;i<length;i++)
    {
        arr2[i]=arr[i];
    }
}
void Nextprev(int*arr,int length)
{
    int arr2[9];
    CopyArray(arr,arr2,9);
    int i=0;

    for(i=0;i<length;i++)
    {

        if(i==length-1)
        {
            arr[i]=(arr2[i])*(arr2[i-1]);
        }
        else if(i==0)
        {
            arr[i]=(arr2[i])*(arr2[i+1]);
        }
        else
        {
            arr[i]=(arr2[i+1])*(arr2[i-1]);
        }
    }
     PrintArray(arr,9);
}
void Next_Prev_Multiplication(void)
{
    int arr[9]={5 ,8 ,1 ,4 ,2 ,9 ,3 ,7 ,6};
    Nextprev(arr,9);
    PrintArray(arr,9);
}
char FindUpperCase(char*string)
{
    char flag=1,i;
    for(i=0;string[i]&&flag;i++)
    {
        if(string[i]>='A' && string[i]<='Z')
        {
            flag=0;

        }
    }

    return string[i-1];
}
char FindUpperCaseRecursion(char*string,int index)
{


        if(string[index]>='A' && string[index]<='Z')
        {
            return string[index];


        }
        else if (!string[index])
        {
            return -1;
        }
        else
        {
            FindUpperCaseRecursion(string,++index);
        }

}
void FindFirstCapital(void)
{
    char*str="hihelloCiao";
    printf("First Found Capital letter is (Recursive method) : \"%c\"\n",FindUpperCaseRecursion(str,0));
     if(FindUpperCase(str)>='A' && FindUpperCase(str)<='Z')
     {
         printf("First Found Capital letter is : \"%c\"\n",FindUpperCase(str));
     }
     else
     {
         printf("No Capital letter found in your sentence\n");
     }
}
void ReverseDisplay(char *string)
{
    int len=StringLength(string);
    printf("String before reverse : %s\n",string);
    printf("String after reverse : ");int c=0,i;
    for( i=len;string[c];i--,c++)
    {
        printf("%c",string[i]);
    }
     printf("%c",string[i]);
    printf("\n");
}
void ReverseString(void)
{
    char*string="hellohellociao";
    ReverseDisplay(string);
}
//123
int  IntRev(int num)
{
    int new_num=0;
   while (num)
   {
       new_num=(new_num*10)+num%10;
       num/=10;
   }
   return new_num;

}
void ReverseInteger(void)
{
    int num;
    printf("Enter number to reverse : ");
    scanf("%d",&num);
    printf("Number after reverse    : %d\n",IntRev(num));

}
int  MaxDiff(int *arr,int length)
{
        BubbleSort(arr,length);
        return (arr[length-1]-arr[0]);
}

int  MaxDiff2(int *arr,int length)
{
    int index_max=0,index_min=0;
    int max=FindMax(arr,length,&index_max);
    int min=FindMin(arr,index_max,&index_min);
    return max-min;
}
int FindMin(int *arr,int length,int *index)
{
    int min=1<<30;
    for (int i=0;i<length;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            (*index)=i;
        }
    }
    return min;

}
void FindMaxDiff(void)
{
    int arr[6]={7 ,9 ,5 ,6 ,13 ,2};
    printf("Max Difference is :%d",MaxDiff2(arr,6));
}
void FindMaxCahr(char*string ,char *max_smal,char*max_Cap)
{
    * max_smal='a';*max_Cap='A';
    for(int i=0;string[i];i++)
    {
        if(string[i] >='A' && string[i]<='Z')
        {
            if(*max_Cap < string[i])
            {
                *max_Cap=string[i];
            }
        }
         if(string[i] >='a' && string[i]<='z')
        {
            if(*max_smal < string[i])
            {
                *max_smal=string[i];
            }
        }
    }
}
int  AnagramCheck(char*str1,char*str2)
{
    char flag=1;
    int l1=StringLength(str1);
    int l2=StringLength(str2);
    if(l1 != l2)
    {
        return -1;
    }
    int max_small,max_Cap,max_small2;
    FindMaxCahr(str1,&max_small,&max_Cap);
    FindMaxCahr(str2,&max_small2,&max_Cap);
    char *freq=calloc(max_small+1,sizeof(char));
    for(int i=0;str1[i];i++)
    {
       freq[str1[i]]++;
       freq[str2[i]]-=1;

    }
    for(int i=0;flag&&(i<=max_small);i++)
    {
        if(freq[i]!=0)
        {
            flag=0;
        }
    }
    free(freq);
    return flag;

}
void IsAnagram(void)
{
    char *string1="spaRe";
    char *string2="peaRs";
     int check =AnagramCheck(string1,string2);
     if(check==-1)
     {
         printf("They are not anagram :(\n");
     }
     else if(check)
     {
        printf("The two strings are anagram :)\n");
     }
     else
     {
         printf("They are not anagram :(\n");
     }
}

void RemoveDuplicate(void)
{
    int arr[10]={1 ,1 ,2 ,3 ,4 ,4 ,5 ,6 ,6 ,6};
    int k;
    int n =FindMax(arr,10,&k);
    int newarr[10]={0};
    int *freq=calloc(n+1,sizeof(int));
    for(int i=0;i<10;i++)
    {
        freq[arr[i]]++;
        if(freq[arr[i]]==1)
        {
           newarr[i]=arr[i];
        }


    }

    k=10;
    for(int i=0;i<10;i++)
    {
        if(newarr[i]==0)
        {
            k--;
            for(int j=i;j<k;j++)
            {
                newarr[j]=newarr[j+1];
            }
        }
    }
    printf("Before remove Duplicates   :");
    PrintArray(arr,10);
    printf("After removeing Duplicates :");
    PrintArray(newarr,10-k);

    free(freq);

}
int RemoveKey(int *arr,int length,int key)
{
    int k=length;
    for(int i=0;i<length;i++)
    {
        if(arr[i]==key)
        {
            k--;i--;
            for(int j=i;j<k;j++)
            {
                arr[j]=arr[j+1];
            }
        }

    }
    return k;
}
void RemoveInstances(void)
{
    int key;
    int arr[10]={1 ,1 ,2 ,3 ,4 ,4 ,5 ,6 ,6 ,6};
    printf("Key Value you want to remove :");
    scanf("%d",&key);
    printf("Size of array after removing %d is -> %d",key,RemoveKey(arr,10,4));
}



typedef struct Car
{
    int CarID;
    float rentalRate;
    char modal[100];

}Car;

void ScanSring(char*str);
int  StringLength(char*str);
int VowelsCount(char *str);
void Cars(void);
void PrintAlphabets(char*str);
void PrintCarData(Car * DisplayCarData);
void ScanCarData(Car *inputCarData);
void CarRentalCost(Car CarData);
void multiplicable_by_5(void);
void lengthofstring(char*string);
void Vowelcount(char *str);
void Scan2DArray(int (*arr)[100],int row,int col);
void Print2DArray(int (*arr)[100],int row,int col);
void compare_2D_Array(void);
void ScanArray(int*arr,int length);
void PrintArray(int*arr,int length);
int FindMax(int *arr,int length,int *index);
void PrintUniqueElements(void);
int onescount_2Darray(int (*arr)[4],int row ,int col);
void ones_rowCounter(void);
void findindex(int (*arr)[4],int row,int col,int key);
void swap(int*a,int*b);
void BubbleSort(int *arr,int length);
void Search2Darray(void);
void Sepreate0s_1s(void);
void RearrangeArray(int * arr,int length);
void zigzagArrangment(void);
void CopyArray(int *arr,int *arr2,int length);
void Nextprev(int*arr,int length);
void Next_Prev_Multiplication(void);
char FindUpperCase(char*string);
char FindUpperCaseRecursion(char*string,int index);
void FindFirstCapital(void);
void ReverseDisplay(char *string);
void ReverseString(void);
int  IntRev(int num);
void ReverseInteger(void);
int FindMin(int *arr,int length,int *index);
int  MaxDiff2(int *arr,int length);
int  MaxDiff(int *arr,int length);
void FindMaxDiff(void);
void IsAnagram(void);
int  AnagramCheck(char*str1,char*str2);
void FindMaxCahr(char*string ,char *max_smal,char*max_Cap);
void RemoveDuplicate(void);
void RemoveInstances(void);
int RemoveKey(int *arr,int length,int key);


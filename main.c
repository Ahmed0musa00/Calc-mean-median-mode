#include <stdio.h>
#define SIZE 99

float mean (const int res []);
float median (int res []);
int mode (const int res [], int freq [], int *modeValue);
void bubbleSort (int res []);


int main(void)
{
    int frequence [10] = {0};
    int modeValue;

    int response[ SIZE ] =
 { 6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
   7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
   6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
   7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
   6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
   7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
   5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
   7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
   7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
   4, 5, 6, 1, 6, 5, 7, 8, 7 };

   printf("the mean is the average value of the data is %f\n",mean(response));
   printf("the median element is %f\n",median(response));
   int large = mode(response, frequence, &modeValue);
   printf("the mode is the most frequent value is %d which occurred %d times\n", modeValue, large);

    return 0;
}

float mean (const int res [])
{
    int sum=0;
    int i;
    for(i=0;i<SIZE;i++)
    {
        sum+=res[i];
    }
    return (float)sum/SIZE ;
}


float median (int res [])
{
  bubbleSort(res);
  if(SIZE%2==0)
  {
      return (res[SIZE/2]+(res[SIZE/2-1]))/2;
  }
  else
    return res[(SIZE-1)/2];
}

int mode (const int res [], int freq [], int *modeValue)
{
    int largest;
    int i;
    for(i=0;i<SIZE;i++)
    {  ++freq[ res[i] ];   }
    largest = freq[0];
    for(i=1;i<10;i++)
    {
        if(freq[i]>largest)
       {
           largest = freq[i];
           *modeValue = i;
       }
    }
    return largest ;
}

void bubbleSort (int res [])
{
    int temp;
    int i;
    int j;
    for(i=1;i<SIZE;i++)
    {
        for(j=0;j<SIZE-1;j++)
        {
            if(res[j]>res[j+1])
            {
               temp=res[j];
               res[j]=res[j+1];
               res[j+1]=temp;
            }
        }
    }
}

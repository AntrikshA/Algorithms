#include<stdio.h>
#include<stdlib.h>

void swap(char str[5], int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void permute(char array[5],int i,int length) { 
  if (length == i){
     printf("%s\n",array);
     return;
  }
  int j = i;
  for (j = i; j < length; j++) { 
     swap(array,i,j);
     permute(array,i+1,length, k);
     swap(array,i,j);
  }
  return;
}
void main()
{
    char string[5]={"ABCDE"};
    permute(string,0,5);
    return;
}
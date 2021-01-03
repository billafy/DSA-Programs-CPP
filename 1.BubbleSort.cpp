#include<iostream>
#include<cmath>
#include<conio.h>
#include<string>

 using namespace std;
 int bubblesort(int x[100], int siz)
 {
  int i,j,temp;
  for(i=0;i<siz;i++)
  {
    for(j=i+1;j<siz;j++)
    {
        if(x[i]>x[j])
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
    }
  }

 }

 int printArray(int x[100],int sizee)
 {
     int i;
   for(i=0;i<sizee;i++)
   {
       cout <<x[i];
       cout << "\n";
   }
 }

 int main()
 {
     int a[100],s,i;
     cout << "Enter the size : ";
     cin >> s;
     cout << "Enter the elements : \n";
     for(i=0;i<s;i++)
     {
       cin >> a[i];
     }
     bubblesort(a,s);
     cout << "The elements in ascending order are : \n";
     printArray(a,s);
 }

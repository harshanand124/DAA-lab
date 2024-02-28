#include<stdio.h>
#include<math.h>
int main()
{
 int n,i,k,l;
 printf("Enter the Number of elements : ");
 scanf("%d",&n);
 int a[n];
 printf("Enter the Elements");
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 printf("Enter the key to search : ");
 scanf("%d",&k);
 if((l=jump(a,n,k))>=0)
 printf("Present at position %d",l);
 else
 printf("Not present");

}
int jump(int a[],int n,int key)
{
 int start=0;
 int end=sqrt(n);
 while( a[end]< key && start<n )
 {
 start=end;
 end+=(sqrt(n));
 if(end>n-1)
 end=n;
 }
 for(int i=start;i<end;i++)
 {
 if(a[i]==key)
 return i;
 }
 return -1;
}
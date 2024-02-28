#include<stdio.h>
int bs(int a[],int n,int x)
{
int l=0,r=n-1;
while(l<=r)
{
int mid=(l+r)/2;
if(a[mid]==x)
return mid;
else if(x< a[mid])
r=mid-1;
else
l=mid+1;
}
return -1;
}
void main()
{
int n;
int a[n],i,j,ans,c=0;
printf("Enter number of eleemnts in sorted manner-\n");
scanf("%d",&n);
printf("Enter the elements-");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
ans=bs(a,n,a[i]+a[j]);
if(ans!=-1)
{
printf("%d %d %d\n",i+1,j+1,ans+1);
c++;
}
}
}
if(c==0)
printf("No sequence found");
}

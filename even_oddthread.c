#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *even(void *m)
{
    int i;
    printf("\nEven numbers: ");
     for(i=1;i<=*(int*)m;i++)
     {
         if(i%2==0)
         printf("%d ",i);
     }
    
}
void *odd(void *m)
{
    int i;
     printf("\nOdd number: ");
     for(i=0;i<=*(int *)m;i++)
     {
         if(i%2!=0)
         printf("%d ",i);    
     }
}
int main(void)
{
    int m;
    printf("Enter any value:\n");
    scanf("%d",&m);
    pthread_t t_id1;
    pthread_t t_id2;
    pthread_create(&t_id1,NULL,&even,&m);
    pthread_join(t_id1,NULL);
    pthread_create(&t_id2,NULL,&odd,&m);
    pthread_join(t_id2,NULL);
    exit;
    
}

#include<stdio.h>
int empty=10;
int mutex=1;
int full=0;
int x=0;
				void producer()
				{

				mutex--;
				empty--;
				full++;
				x++;
				printf("Item is Produced  %d",x);
				mutex++;
				}
			void consumer()
			{

			mutex--;
			empty++;
			full--;
			x--;
			printf("Item is consumed  %d",x);
			mutex++;
			}
int main()
{
int n;
int i;
		do
		{
		printf("\n1.Producer\n2.Consumer\n3.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
	            if((mutex==1)&&empty!=0)
	            {
	            producer();
	            } 	
	            else
	            {
	            printf("Buffer is full");
	            }
	            break;
	     case 2:
	     		 if((mutex==1)&&full!=0)
	            {
	            consumer();
	            } 	
	            else
	            {
	            printf("Buffer is empty");
	            }
	            break;
	      case 3:
	           break;
	     
		}
		printf("\nDo you want to contrinue if yes then press 1:");
		scanf("%d",&i);
		}while(i==1);
return 0;
}

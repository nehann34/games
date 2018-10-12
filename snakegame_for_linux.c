#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'

int front=-1;
int rear=-1;       

char dir='R';
int length=2;

int score=0;

struct coordinates
{
	int row;
	int col;
};



char **create_map(int m,int n)
{
	char **a;
	a=(char **)malloc(n*sizeof(char *));

	for(int i=0;i<n;i++)
		a[i]=(char *)malloc(m*sizeof(char));
	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
			a[i][j]=' '; 
	for(int i=1;i<m-1;i++)
		a[i][0]='|';
	
	for(int i=0;i<n;i++)
		a[0][i]='-';
	
	for(int i=1;i<m-1;i++)
		a[i][n-1]='|';

	for(int i=0;i<n;i++)
		a[m-1][i]='-';
	return a;
}


char *create_queue(int m,int n)
{
	char *q;
	q=(char *)malloc(m*n*sizeof(char));
	return q;

}

int is_full(int m,int n)
{
	if(front==0 && rear==(m*n)-1)
		return 1;
	return 0;
}

int is_empty()
{
	if(front == -1 || (front==rear+1))
		return 1;
	return 0;
}

void insert(char *q,char c,int m,int n)
{
	if(is_full(m,n))
	{
		printf("Queue is full\n");
		return;
	}
	if(front == -1)
		front=0;
	rear=rear+1;
	q[rear]=c;
}

char delete(char *q)
{
	char c;
	if(is_empty())
	{
		printf("Queue is empty\n");
		exit(0);
	}
	c=q[front];
	front=front+1;
	return c;
}
void generate_food(struct coordinates food,char **a,int m,int n)
{
	food.row=rand()%n;
	food.col=rand()%m;
	if(food.col==0 || food.row==0 || food.row==n-1 || food.col==m-1 || a[food.row][food.col]=='*')
		generate_food(food,a,m,n);
	else
		a[food.row][food.col]='$';

}

void instructions()
{
	printf("-----------------------------THIS IS A SNAKE GAME!!!------------------------------\n\n");
	printf("-----------------------------INSTRUCTIONS TO PLAY----------------------------------\n\n");
	printf("Type U to move snake in upwards direction\n");
	printf("Type D to move snake in downwards direction\n");
	printf("Type L to move snake in left direction\n");
	printf("Type R to move snake in right direction\n\n");	
}


int main()
{
	srand(time(0));
	int m,n,c=0;
	char **a,*q;
	char d,prev;
	struct coordinates head,tail,food;
	
	instructions();
	printf("Enter dimensions for the border of snake game!!!\n");
	scanf("%d %d",&m,&n);
	a=create_map(m,n);
	q=create_queue(m,n);
	
	head.row=3;
	head.col=3;
	tail.row=3;
	tail.col=2;
	
	insert(q,dir,m,n);
	a[head.row][head.col]='*';
	a[tail.row][tail.col]='*';
	
	generate_food(food,a,m,n);
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",a[i][j] );
			printf("\n");
		}
	for(;;)
	{
		printf("Enter direction to play!!!\n");
		// scanf(" %c",&d);
		

		if(!kbhit())
		{
			

			if(dir=='R')
			{
				printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
					
						(head.col)++;
						//a[tail.row][tail.col]=' ';
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='R';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='R';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
							continue;
			}



			if(dir=='U')
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						
						(head.row)--;
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==0 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='U';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='U';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
					}
				


					if(dir=='L')
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						
						//a[tail.row][tail.col]=' ';
						(head.col)--;
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='L';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='L';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
						
					}



					if(dir=='D')
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						(head.row)++;
						
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='D';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='D';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
					}
}

else		
	{
		d=getchar();
		
		if(d=='U')
		{
			switch(dir)
			{
				case 'R':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						
						
						(head.row)--;
						
						if(head.row==0 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='U';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
							
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='U';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);

							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
					}
				case 'L':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						
						(head.row)--;
						
						
						if(head.row==0 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='U';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='U';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);

							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
					}

				case 'U':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						
						(head.row)--;
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==0 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='U';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='U';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
					}
				case 'D':
					{
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
					}


			}
			
		}


		if(d=='D')
		{
			switch(dir)
			{
				case 'R':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						(head.row)++;
					
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='D';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='D';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
										}
				case 'L':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						(head.row)++;
						
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='D';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='D';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
					}

				case 'U':
					{
						
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
					}
				case 'D':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						(head.row)++;
						
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='D';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='D';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
					}


			}
			
		}
		if(d=='R')
		{
			switch(dir)
			{
				case 'R':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
					
						(head.col)++;
						//a[tail.row][tail.col]=' ';
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='R';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='R';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
										}
				case 'L':
					{
						
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
					}

				case 'U':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						(head.col)++;
						
						//a[tail.row][tail.col]=' ';
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';

							dir='R';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='R';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
					}
				case 'D':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						(head.col)++;
						
						//a[tail.row][tail.col]=' ';
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='R';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[head.row][head.col]='*';
								a[tail.row][tail.col]=' ';
								dir='R';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
							continue;
					}


			}
			
		}

		if(d=='L')
		{
			switch(dir)
			{
				case 'R':
					{
						
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
						continue;
						}
				case 'L':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						
						
						//a[tail.row][tail.col]=' ';
						(head.col)--;
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='L';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								dir='L';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
						
					}

				case 'U':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						(head.col)--;
					
						//a[tail.row][tail.col]=' ';
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='L';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='L';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++)
									printf("%c",a[i][j] );
								printf("\n");
							}
											continue;
					}
				case 'D':
					{
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						(head.col)--;
						
						//a[tail.row][tail.col]=' ';
						//printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							a[head.row][head.col]='*';
							a[tail.row][tail.col]='*';
							dir='L';
							insert(q,dir,m,n);
							generate_food(food,a,m,n);
						}
						else
							{
								a[tail.row][tail.col]=' ';
								a[head.row][head.col]='*';
								
								dir='L';
								prev=delete(q);
								if(prev=='R')
									(tail.col)++;
								if(prev=='D')
									(tail.row)++;
								if(prev=='U')
									(tail.row)--;
								if(prev=='L')
									(tail.col)--;
								insert(q,dir,m,n);
							}
						printf("%d %d %d %d\n",tail.row,tail.col,head.row,head.col );
						for(int i=0;i<n;i++)
							{
								for(int j=0;j<m;j++) 
									printf("%c",a[i][j] );
								printf("\n");
							}
							continue;
					}


			}
			
		}
	}		

	}
	return 0;
}

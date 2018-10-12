#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define UP 'U'   
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'
#define WAIT 200

clock_t wait_time=WAIT;
int front=-1;
int rear=-1;
int k=4000;
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
	char *q=(char *)malloc(m*n*sizeof(char));
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

char del(char *q)
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
	printf("-------------------------Speed of snake will increase after 5 units of food---------------------------------\n\n");
	printf("Type U to move snake in upwards direction\n");
	printf("Type D to move snake in downwards direction\n");
	printf("Type L to move snake in left direction\n");
	printf("Type R to move snake in right direction\n\n");	
}

char wait(clock_t wait_time,char dir)
{
	clock_t start,runafter;
	start=clock();
	runafter=start+wait_time;
	char ch;
	while(runafter>start)
	{
		if(kbhit())	
		{
			ch=getch();
			return ch;
		}
		start=clock();
	}	
	return dir;
}

void display(char **a,int m,int n)
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",a[i][j] );
			printf("\n");
		}
		system("cls");
}

int main()
{
	srand(time(0));
	int m,n,c=0;
	char **a,*q;
	char d,prev;
	struct coordinates head,tail,food;
	int s=0;
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
	display(a,m,n);
	for(;;)
	{
		
		char d;
		if(score/5 > s)
			wait_time=k/score;
			
		d=wait(wait_time,dir);
			
		
		if(d=='U')
		{
			switch(dir)
			{
				case 'R':
					{
						
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
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						
						display(a,m,n);
						continue;
					}
				case 'L':
					{
						
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
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						
						display(a,m,n);
						continue;
					}

				case 'U':
					{
						
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
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						
						display(a,m,n);
						continue;
					}
				case 'D':
					{
						display(a,m,n);
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
						
						(head.row)++;
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
					display(a,m,n);
					continue;
										}
				case 'L':
					{
						(head.row)++;
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
						continue;
					}

				case 'U':
					{
						
						display(a,m,n);
						continue;
					}
				case 'D':
					{
						
						(head.row)++;
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
					
						display(a,m,n);
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
						(head.col)++;
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
						continue;
										}
				case 'L':
					{
						
						display(a,m,n);
						continue;
					}

				case 'U':
					{
						(head.col)++;
						
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
						continue;
					}
				case 'D':
					{
						(head.col)++;
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
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
						
						display(a,m,n);
						continue;
						}
				case 'L':
					{
						(head.col)--;
						if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
						continue;
						
					}

				case 'U':
					{
						(head.col)--;
					if(head.col==n-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
											continue;
					}
				case 'D':
					{
						(head.col)--;
						if(head.row==m-1 || a[head.row][head.col]=='*')
						{
							printf("GAME OVER!!!\n");
							printf("Score is %d\n",score );
							return 0;
						}
						if(a[head.row][head.col]=='$')
						{
							score++;
							if(score%5==0)
								s++;
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
								prev=del(q);
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
						display(a,m,n);
							continue;
					}


			}
			
		}
		
		



	}
	return 0;
}


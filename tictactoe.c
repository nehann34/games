#include<stdio.h>

int win(char board[][3],char p1,char p2)
{
	if((board[0][0] ==p1 && board[1][0]==p1 && board[2][0]==p1) || (board[0][1] ==p1 &&
		board[1][1]==p1 && board[2][1]==p1) || (board[0][2] ==p1 && board[1][2]==p1 && board[2][2]==p1)
		||(board[0][0] ==p1 && board[0][1]==p1 && board[0][2]==p1)||(board[1][0] ==p1 && board[1][1]==p1
			&& board[1][2]==p1) || (board[2][0] ==p1 && board[2][1]==p1 && board[2][2]==p1) ||(board[0][0]==p1 && 
				board[1][1]==p1 && board[2][2]==p1)||(board[0][2] ==p1 && board[1][1]==p1 && board[3][0]==p1))

		return 1;

	if((board[0][0] ==p2 && board[1][0]==p2 && board[2][0]==p2) || (board[0][1] ==p2 &&
		board[1][1]==p2 && board[2][1]==p2) || (board[0][2] ==p2 && board[1][2]==p2 && board[2][2]==p2)
		||(board[0][0] ==p2 && board[0][1]==p2 && board[0][2]==p2)||(board[1][0] ==p2 && board[1][1]==p2
			&& board[1][2]==p2) || (board[2][0] ==p2 && board[2][1]==p2 && board[2][2]==p2) ||(board[0][0]==p2 && 
				board[1][1]==p2 && board[2][2]==p2)||(board[0][2] ==p2 && board[1][1]==p2 && board[3][0]==p2))

		return 2;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==' ')
				return 3;
		}
	}
return 0;
}

void showinstructions()
{
	printf("This is a tic tac toe board..choose numbers from 1-9 to play.\n");
	printf("\n");
	printf(" 1 | 2 | 3 \n");
	printf("-----------\n");
	printf(" 4 | 5 | 6 \n");
	printf("-----------\n");
	printf(" 7 | 8 | 9 \n");
}

void showboard(char board[][3])
{
	for(int i=0;i<3;i++)
		{
			printf("%c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
			if(i==2)
				break;
			else
				printf("------------------\n");
		}
	return ;
}

void initialize(char board[][3])
{
	char a=' ';
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	board[i][j]=a;
}

int playtictactoe(int start,char board[][3],char p1,char p2)
{
	initialize(board);
		if(start==1)
			{
				for(int i=0;i<9;i++)
					{
						int iswin,num;
							if(i%2==0)
								{
									printf("Player1 chance....Enter number to play..\n");
									scanf("%d",&num);
									switch(num)
									{
										case 1:
											{
												board[0][0]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;
											}
										case 2:
											{
												board[0][1]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;
											}
										case 3:
											{
												board[0][2]=p1;

												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;

											}
										case 4:
											{

												board[1][0]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;

											}
										case 5:
											{

												board[1][1]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;

											}
										case 6:
											{

												board[1][2]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;

											}

										case 7:
											{
												board[2][0]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;
											}
										case 8:
											{
												board[2][1]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;
											}
										case 9:
											{
												board[2][2]=p1;
												showboard(board);
												iswin=win(board,p1,p2);
												if(iswin==1)
												return 1;
												if(iswin==0)
												return 0;
												if(iswin==2)
												return 2;
												if(iswin==3)
												continue;
												break;
											}
									}
							}
					else
						{
							printf("Player2 chance....Enter number to play..\n");
							scanf("%d",&num);
							switch(num)
								{
									case 1:
										{
											board[0][0]=p2;

											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}
									case 2:
										{

											board[0][1]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}
									case 3:
										{

											board[0][2]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}
									case 4:
										{

											board[1][0]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}

									case 5:
										{

											board[1][1]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}
									case 6:
										{

											board[1][2]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}
									case 7:
										{

											board[2][0]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;

										}
									case 8:
										{

											board[2][1]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)

											continue;
											break;
										}
									case 9:
										{
											board[2][2]=p2;
											showboard(board);
											iswin=win(board,p1,p2);
											if(iswin==1)
											return 1;
											if(iswin==0)
											return 0;
											if(iswin==2)
											return 2;
											if(iswin==3)
											continue;
											break;
										}
								}
						}
				}
		}
					if(start==2)
							{
								for(int i=0;i<9;i++)
									{
										int iswin,num;
										if(i%2==0)
											{
												printf("Player2 chance....Enter number to play..\n");
												scanf("%d",&num);
												switch(num)
													{
														case 1:
															{
																board[0][0]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;
															}
														case 2:
															{
																board[0][1]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;

																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 3:
															{

																board[0][2]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 4:
															{

																board[1][0]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 5:
															{

																board[1][1]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 6:
															{

																board[1][2]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)

																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 7:
															{

																board[2][0]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 8:
															{

																board[2][1]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}
														case 9:
															{

																board[2][2]=p2;
																showboard(board);
																iswin=win(board,p1,p2);
																if(iswin==1)
																return 1;
																if(iswin==0)
																return 0;
																if(iswin==2)
																return 2;
																if(iswin==3)
																continue;
																break;

															}

												}
									}

										else
										{

											printf("Player1 chance....Enter number to play..\n");
											scanf("%d",&num);
											switch(num)

												{

													case 1:
													{

														board[0][0]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 2:
													{

														board[0][1]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 3:
													{

														board[0][2]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 4:
													{

														board[1][0]=p1;
														showboard(board);

														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 5:
													{

														board[1][1]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 6:
													{

														board[1][2]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 7:
													{

														board[2][0]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;

													}
													case 8:

													{
														board[2][1]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;
													}
													case 9:
													{
														board[2][2]=p1;
														showboard(board);
														iswin=win(board,p1,p2);
														if(iswin==1)
														return 1;
														if(iswin==0)
														return 0;
														if(iswin==2)
														return 2;
														if(iswin==3)
														continue;
														break;
													}
												}
										}
								}
						}
				}

int main()
	{
		char p1,p2;
		int start,winner;
		char board[3][3];
		printf("---------THIS IS A TIC TAC TOE GAME-----------\n");
		printf("Enter sign for player1 and player2 respectively\n");
		scanf("%c %c",&p1,&p2);
		showinstructions();
		printf("Enter player to start with\n");
		scanf("%d",&start);
		winner=playtictactoe(start,board,p1,p2);
		if(winner==0)
			printf("Tie\n");
		if(winner==1)
			printf("Player1 wins\n");
		if(winner==2)
			printf("Player2 wins\n");
		return 0;
}
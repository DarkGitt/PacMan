#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <sys/ioctl.h>
using namespace std;
//////////////////////////////////////////////////////////////////
bool kbhit() // https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux
{   
    usleep(50000); // В мілісікундах
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}
//<>
int mygetch() {
struct termios oldt,
newt;
int ch;
tcgetattr( STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}
//////////////////////////////////////////////////////////////////
//////Class Pola///////////
class Pola{
				protected:
								// Lvl parametres
								static	const int pole_x = 20;
						    static	const int pole_y = 10;
								static  int level;

								//Lvl1
								static const int Coins_first = 88;
								static string pole_first[pole_y][pole_x];
								//lvl2
								static const int Coins_second = 84;
								static string pole_second[pole_y][pole_x];

								//lvl3
								static const int Coins_third = 113;
								static string pole_third[pole_y][pole_x];

								//lvl4
								static const int Coins_forth = 108;
								static string pole_forth[pole_y][pole_x];
};

//////lvl1//////////////
int Pola::level = 1;
string Pola::pole_first[pole_y][pole_x] = {
//									1		2		3		4		5		6		7		8		9		10	11	12	13	14	15	16	17	18	19	20
									{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},//1
									{"#","*","*","*","*","*","*","*","*","#","#","*","*","#","O","*","*","*","*","#"},//2
									{"#","*","O","#","*","#","#","*","#","#","#","#","*","#","#","#","#","#","*","#"},//3
									{"#","#","#","#","*","#","#","*","*","*","*","*","*","*","*","*","*","*","*","#"},//4
									{"#","*","*","*","*","*","*","*","#","#","#","#","*","#","*","*","#","#","*","#"},//5
  					    	{"#","#","#","#","#","#","#","*","#","*","*","#","*","#","#","*","#","*","*","#"},//6
									{"#","*","*","*","*","*","*","*","*","*","*","*","*","*","#","*","#","O","*","#"},//7
									{"#","*","#","#","#","#","*","#","#","#","#","#","*","#","#","*","#","#","#","#"},//8
									{"#","*","*","*","O","#","*","*","*","*","*","*","*","*","*","*","*","*","#","#"},//9
									{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"} //10
							};
//////lvl1 end////////
//////lvl2/////////// 
string Pola::pole_second[pole_y][pole_x] = {
//									1		2		3		4		5		6		7		8		9		10	11	12	13	14	15	16	17	18	19	20
									{"#","#","#","#","#","#","#","#","#","1","1","#","#","#","#","#","#","#","#","#"},//1
									{"#","*","*","*","*","*","#","#","*","*","*","*","*","*","#","*","*","#","*","#"},//2
									{"#","O","#","*","#","#","#","#","#","#","*","#","#","#","#","*","*","#","*","#"},//3
									{"#","#","#","*","#","*","*","*","*","*","*","*","*","*","#","*","#","#","*","#"},//4
									{"#","*","*","*","#","*","#","*","*","#","#","*","#","*","#","O","*","*","*","#"},//5
  					    	{"#","*","#","#","#","*","#","*","*","*","#","*","#","*","#","#","#","#","*","#"},//6
									{"#","*","*","*","*","*","#","*","*","#","#","O","#","*","*","*","*","*","*","#"},//7
									{"#","*","#","*","#","#","#","*","#","#","#","#","#","#","*","#","*","#","#","#"},//8
									{"#","*","#","*","*","#","*","*","#","*","*","#","*","*","*","#","*","*","#","#"},//9
									{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"} //10
							};
//////lvl2 end///////
//////lvl3///////////
string Pola::pole_third[pole_y][pole_x] = {
//									1		2		3		4		5		6		7		8		9		10	11	12	13	14	15	16	17	18	19	20
									{"#","1","1","#","#","#","#","#","#","#","#","#","#","#","#","#","#","1","1","#"},//1
									{"4","*","*","*","*","*","*","*","*","*","#","O","*","*","*","#","*","*","*","3"},//2
									{"4","*","*","*","*","*","*","*","*","*","#","*","*","*","*","#","*","*","*","3"},//3
									{"#","*","*","*","*","*","*","*","*","*","#","*","*","*","*","*","*","*","*","#"},//4
									{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#"},//5
  					    	{"#","*","*","*","*","*","*","*","*","*","#","O","*","*","*","*","*","*","*","#"},//6
									{"#","*","*","*","*","*","*","*","*","*","#","*","*","*","*","*","*","*","*","#"},//7
									{"4","*","*","*","*","*","*","*","*","*","#","*","*","*","*","#","#","#","*","3"},//8
									{"4","*","*","*","*","*","*","*","*","*","#","*","*","*","*","#","*","*","*","3"},//9
									{"#","2","2","#","#","#","#","#","#","#","#","#","#","#","#","#","#","2","2","#"} //10
							};
//////lvl3 end///////
//////lvl4///////////
string Pola::pole_forth[pole_y][pole_x] = {
//									1		2		3		4		5		6		7		8		9		10	11	12	13	14	15	16	17	18	19	20
									{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","1","#","#","#","6","#"},//1
									{"#","*","*","*","#","*","*","*","*","*","#","*","*","#","*","*","*","*","*","#"},//2
									{"#","*","*","*","#","*","*","*","*","#","#","*","*","#","*","*","*","*","*","#"},//3
									{"#","*","*","*","#","*","#","#","#","#","*","*","*","*","*","*","*","*","*","#"},//4
									{"#","*","*","*","*","*","*","*","#","*","*","*","*","#","*","*","*","*","*","#"},//5
  					    	{"#","*","*","*","*","*","*","*","#","*","*","*","*","#","#","#","*","*","*","#"},//6
									{"#","*","*","#","#","#","#","*","#","#","#","#","*","*","*","#","*","*","*","#"},//7
									{"#","*","#","#","*","*","*","*","*","*","*","#","#","*","*","#","*","*","*","#"},//8
									{"#","*","#","*","*","*","*","*","*","*","*","*","#","#","*","#","*","*","*","#"},//9
									{"#","5","#","#","#","#","#","#","#","#","#","#","#","#","2","#","#","#","#","#"} //10
							};
//////lvl4 end///////

//////Class Pola End///////
///////Class Plane/////////
class Plane:public Pola{							    
				protected:
									static string pole[pole_y][pole_x];
									static string Head;
									static int coins,coins_max;
									static bool GameWin;

									float frames = 0; // For class enemy
									static void Lvl_change();
				public:
								static void Draw(int player_x,int player_y,
																int enemy_1_x,int enemy_1_y,
																int enemy_2_x,int enemy_2_y,
																int enemy_3_x,int enemy_3_y,
																int enemy_4_x,int enemy_4_y);
								static bool GameRun;
								int x,y;
};
bool Plane::GameRun = true;
bool Plane::GameWin = false;
string Plane::Head = "^";
int Plane::coins = 0;
int Plane::coins_max = Coins_first;
string Plane::pole[pole_y][pole_x] = pole_first;


void Plane::Lvl_change(){ // Фукцыя подмены левела
		coins = 0;
		level++;
		if(level == 2){
					coins_max = Coins_second;
					for (int i = 0;i < pole_y;i++){
							for(int u = 0;u < pole_x;u++)
									pole[i][u] = pole_second[i][u];
					}
		}
		else if(level == 3){
					coins_max = Coins_third;
					for (int i = 0;i < pole_y;i++){
							for(int u = 0;u < pole_x;u++)
									pole[i][u] = pole_third[i][u];
					}
		}
		else if(level == 4){
					coins_max = Coins_forth;
					for (int i = 0;i < pole_y;i++){
							for(int u = 0;u < pole_x;u++)
									pole[i][u] = pole_forth[i][u];
					}
		}
		else {GameRun = false;GameWin = true;}
					
}

void Plane::Draw(int player_x,int player_y,
								int enemy_1_x,int enemy_1_y,
								int enemy_2_x,int enemy_2_y,
								int enemy_3_x,int enemy_3_y,
								int enemy_4_x,int enemy_4_y){
										system("clear");
										for (int f_y = 0;f_y < pole_y;f_y++){
												for (int f_x = 0;f_x < pole_x;f_x++){
																if(f_x == player_x && f_y == player_y)
																				cout << Head;
																else if(f_x == enemy_1_x && f_y == enemy_1_y || f_x == enemy_2_x && f_y == enemy_2_y || f_x == enemy_3_x && f_y == enemy_3_y || f_x == enemy_4_x && f_y == enemy_4_y)
																				cout << "∆";
																else if (pole[f_y][f_x] == "1" || pole[f_y][f_x] == "2" || pole[f_y][f_x] == "3" || pole[f_y][f_x] == "4" || pole[f_y][f_x] == "5" || pole[f_y][f_x] == "6")
																				cout << " ";
																else
																				cout << pole[f_y][f_x];
												}
										cout << endl;
										}
										cout <<"Coins: "<< coins << endl;
										if (GameRun == false)
														if (GameWin == true)
																cout << "You win!!!\n";	
														else
																cout << "You lose!!!" << endl;												
										}		
///////Class Plane End////////
///////Class Hero////////////
class Hero : public Plane{
				public:
					Hero(int x,int y){
								 this->x = x;
								 this->y = y;
					}
					void PMove(int& hero_x,int& hero_y,
														int& e1_x,int& e1_y,
															int& e2_x,int& e2_y,
																int& e3_x,int& e3_y,
																	int& e4_x,int& e4_y){
							if (coins == coins_max){Lvl_change();
																				hero_x = 9; hero_y = 5;		
																					e1_x = 8; e1_y = 1;
																						e2_x = 4; e2_y = 8;
																					e3_x = 15; e3_y = 3;
																				e4_x = 17; e4_y = 8;
							}
							if (pole[y][x] == "*"){coins++;pole[y][x] = " ";} //Toch to coins
							if (pole[y][x] == "O"){coins++;pole[y][x] = " ";} //Toch to big coins
							/////tp_muve/////
							if (pole[y][x] == "1") y = 8; 
							if (pole[y][x] == "2") y = 1;
							if (pole[y][x] == "3") x = 1; 
							if (pole[y][x] == "4") x = 18;
							if (pole[y][x] == "5"){x = 18;y = 1;} 
							if (pole[y][x] == "6"){x = 1;y = 8;} 
							/*
							1 = телепортацыя вниз
							2 = телепортацыя верх
							3 = телепортацыя не лево
							4 = телепортацыя на право
							 */

							if(kbhit()){																			//Move
											switch (mygetch())
											{
													case 'i':
															//GameRun = false;
															coins = coins_max;
															break;
													case 'd':
															if (pole[y][x+1] != "#")
																	x++;
															Head = ">";
															break;
													case 'a':
															if (pole[y][x-1] != "#")
																	x--;
															Head = "<";
															break;
													case 'w':
															if (pole[y-1][x] != "#")
																	y--;
															Head = "^";
															break;
													case 's':
															if (pole[y+1][x] != "#")
																	y++;
															Head = "V";
															break;
											}
							}	
					}
};
///////Class Hero End/////////
///////Class Enemy////////////
class Enemy:public Plane {
				protected:
								int data;
								int data2;
								int x_data,y_data;

								///////Enemy Lost/////
								bool Enemy_Lost = false;
								bool Enemy_Run = true;
								float frames_tp = 0;
				public:
								Enemy(int x,int y = 1){
										this->x = x;
										this->y = y;
								}
								void EnemyRun(int r_num,int hero_x,int hero_y){
									frames += 0.05;// Ходьба
									data2 = frames;
									
									if (data != data2 && Enemy_Run){
											if (x < hero_x && pole[y][x+1] != "#")
													x++;
											else if (x > hero_x && pole[y][x-1] != "#")
													x--;
											else{
													if (r_num == 2 && pole[y][x+1] != "#")
															x++;
													else if (r_num == 1 && pole[y][x-1] != "#")
															x--;
											}
											if (y < hero_y && pole[y+1][x] != "#")
													y++;
											else if (y > hero_y  && pole[y-1][x] != "#")
													y--;
											else{
													if (r_num == 3 && pole[y+1][x] != "#")
															y++;
													else if (r_num == 4 && pole[y-1][x] != "#")
															y--;
											}				
											data = data2;
									if (frames < 50)
											frames = 0;
									
									}
								}
								void Enemy_Hit(int Hero_x,int Hero_y){
										if (Hero_x == x && Hero_y == y && Enemy_Run){
												GameRun = false;
										}
										if (pole[Hero_y][Hero_x] == "O" || Enemy_Lost){
														if (pole[Hero_y][Hero_x] == "O")
																	frames_tp = 0;
												Enemy_Lost = true;
												frames_tp += 0.05;
												if (frames_tp <= 0.10){Enemy_Run = false;}	
												else if (frames_tp > 5){frames_tp = 0;Enemy_Lost = false;Enemy_Run = true;}		
										}
								}
};
//////Class Enemy End/////////
int main(){
				int r_num;
				Hero Tk(9,5);//Рахуем з нуля 
				Enemy E1(8);
				Enemy E2(4,8);
				Enemy E3(15,3);
				Enemy E4(17,8);

				srand(time(0));
				r_num = rand() % 5;
				while(Plane::GameRun){	
								//////Enemy Action//////
								r_num = rand() % 5;
								E1.EnemyRun(r_num,Tk.x,Tk.y);
								E1.Enemy_Hit(Tk.x,Tk.y);

								r_num = rand() % 5;
								E2.EnemyRun(r_num,Tk.x,Tk.y);
								E2.Enemy_Hit(Tk.x,Tk.y);

								r_num = rand() % 5;
								E3.EnemyRun(r_num,Tk.x,Tk.y);
								E3.Enemy_Hit(Tk.x,Tk.y);

								r_num = rand() % 5;
								E4.EnemyRun(r_num,Tk.x,Tk.y);
								E4.Enemy_Hit(Tk.x,Tk.y);
								//////Hero Action///////
								Tk.PMove(Tk.x,Tk.y,E1.x,E1.y,E2.x,E2.y,E3.x,E3.y,E4.x,E4.y);
								//////Pole//////////////
								Plane::Draw(Tk.x,Tk.y,E1.x,E1.y,E2.x,E2.y,E3.x,E3.y,E4.x,E4.y);
				}
}

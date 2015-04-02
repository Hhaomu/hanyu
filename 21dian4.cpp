//21 point game.cpp
//Play it!
#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;


int main() {
	int i=0,num1,num2,num3,num4,num5,num6,num7,num8,num9,p=0;
    //p is for judging whether to judge player and computer or not;
	char flag,flag1;
	//judging whether to play or whther continue to give poker;
	char card1,card2; 										//only use it for selecting different poker;
	int a[4][13] = {{1,2,3,4,5,6,7,8,9,10,11,12,13},{14,15,16,17,18,19,20,21,22,23,24,25,26},{27,28,29,30,31,32,33,34,35,36,37,38,39},{40,41,42,43,44,45,46,47,48,49,50,51,52}};
	//simulate a group of poker;
	srand(time(NULL));										//initialize the seed;
	while (true) {
		float num10=0;  									//final player's point';
		cout << "Need to play the games?(N/Y)"  << endl;
		cin >> flag;
	
		if (flag=='Y'||flag=='y'){
			cout << "Player's round!" <<endl;
			while(i==0){
				num1 = rand() * 4 / (RAND_MAX + 1) + 1;		//generate color;
				num2 = rand() * 13 / (RAND_MAX + 1) + 1;	//generate number;
				num3 = a[num1][num2];						//generate the first poker;
				num4 = rand() * 4 / (RAND_MAX + 1) + 1;		//generate color;
				num5 = rand() * 13 / (RAND_MAX + 1) + 1;	//generate number;
				num6 = a[num4][num5];						//generate the second poker;


				if ((num1 != num4)||(card1 != card2)){		//judge whether the two pokers are the same;
					a[num1][num2] = -1;						//stand for the poker has been selected,which is benefit for further selection;
					a[num4][num5] = -1;
					++i;				
				}
				else continue;		
			}
			cout << "You have got the cards:" << endl;
			switch (num1){									//judge the first poker's suit
				case 1: cout << "hei tao";break;
				case 2: cout <<"hong tao";break;
				case 3: cout << "mei hua";break;
				case 4: cout << "fang kuai";break;}
			switch (num3%13){								//judge the number;
				case 0: card1 = 'A';num10+=1;cout << "A" << endl ;break;
				case 1: card1 = '2';num10+=2;cout << "2" << endl ;break;
				case 2: card1 = '3';num10+=3;cout << "3" << endl ;break;
				case 3: card1 = '4';num10+=4;cout << "4" << endl ;break;
				case 4: card1 = '5';num10+=5;cout << "5" << endl ;break;
				case 5: card1 = '6';num10+=6;cout << "6" << endl ;break;
				case 6: card1 = '7';num10+=7;cout << "7" << endl ;break;
				case 7: card1 = '8';num10+=8;cout << "8" << endl ;break;
				case 8: card1 = '9';num10+=9;cout << "9" << endl ;break;
				case 9: card1 = '0';num10+=10;cout << "10" << endl ;break;
				case 10: card1 = 'J';num10+=0.5;cout << "J" << endl ;break;
				case 11: card1 = 'Q';num10+=0.5;cout << "Q" << endl ;break;
				case 12: card1 = 'K';num10+=0.5;cout << "K" << endl ;break;								
			}			

			switch (num4){									//judge the second poker's suit;
				case 1: cout << "hei tao";break;
				case 2: cout << "hong tao";break;
				case 3: cout << "mei hua";break;
				case 4: cout << "fang kuai";break;}
			switch (num6%13){								//judge the number;
				case 0: card2 = 'A';cout << "A" << endl ;num10+=1;break;
				case 1: card2 = '2';cout << "2" << endl ;num10+=2;break;
				case 2: card2 = '3';cout << "3" << endl ;num10+=3;break;
				case 3: card2 = '4';cout << "4" << endl ;num10+=4;break;
				case 4: card2 = '5';cout << "5" << endl ;num10+=5;break;
				case 5: card2 = '6';cout << "6" << endl ;num10+=6;break;
				case 6: card2 = '7';cout << "7" << endl ;num10+=7;break;
				case 7: card2 = '8';cout << "8" << endl ;num10+=8;break;
				case 8: card2 = '9';cout << "9" << endl ;num10+=9;break;
				case 9: card2 = '0';cout << "10" << endl ;num10+=10;break;
				case 10: card2 = 'J';cout << "J" << endl ;num10+=0.5;break;
				case 11: card2 = 'Q';cout << "Q" << endl ;num10+=0.5;break;
				case 12: card2 = 'K';cout << "K" << endl ;num10+=0.5;break;								
			}				
		
			int color[22] = {num1,num4};					//set the array for showing the poker the player have selected every time;
			int card[22] ={num3%13,num6%13};		
			int times = 2;									//it's the number of poker you have owned;
			int i1=0;
			while (i1==0){
				cout << "Continue to give poker?(N/Y)" << endl;
				cin >> flag1;
			
				if (flag1=='Y'||flag1=='y'){
					num7 = rand() * 4 / (RAND_MAX + 1) + 1;
					num8 = rand() * 13 / (RAND_MAX + 1) + 1;
					num9 = a[num7][num8];
					if (num9==-1) continue;
					else a[num7][num8] = -1;
					switch (num9%13){
						case 0: num10+=1;break;	//add the number of point of each poker;
						case 1: num10+=2;break;
						case 2: num10+=3;break;
						case 3: num10+=4;break;
						case 4: num10+=5;break;
						case 5: num10+=6;break;
						case 6: num10+=7;break;
						case 7: num10+=8;break;
						case 8: num10+=9;break;
						case 9: num10+=10;break;
						case 10: num10+=0.5;break;
						case 11: num10+=0.5;break;
						case 12: num10+=0.5;break;
					}
					color[times] = num7;
					card[times] = num9%13;
					cout << "You have the cards:"<< endl;
					for (int k=0;k<=times;++k){				//cout every poker You have selected;
						switch (color[k]){
							case 1: cout<<"hei tao";break;
					        case 2: cout<<"hong tao";break;
							case 3: cout<<"mei hua";break;
							case 4: cout<<"fang kuai";break;
						}
						switch (card[k]){
							case 0: cout<<"A"<< endl;break;
							case 1: cout<<"2"<< endl;break;
							case 2: cout<<"3"<< endl;break;
							case 3: cout<<"4"<< endl;break;
							case 4: cout<<"5"<< endl;break;
							case 5: cout<<"6"<< endl;break;
							case 6: cout<<"7"<< endl;break;
							case 7: cout<<"8"<< endl;break;
							case 8: cout<<"9"<< endl;break;
							case 9: cout<<"10"<< endl;break;
							case 10: cout<<"J"<< endl;break;
							case 11: cout<<"Q"<< endl;break;
							case 12: cout<<"K"<< endl;break;
						}
					}
					++times;									//add the number of poker;
					if (num10>21) {cout << "You have lost!" << endl;p=2;++i1;flag='N';//p is 2 so the final judge is broken;
					}
				}
				else if (flag1=='N'||flag1=='n') ++i1;
				else cout << "Please input N or Y!";
			}
				
			if (flag=='Y'||flag=='y') {						//judge whether to skip the computer's round;
				
				
							
			cout << "Computer's round!" << endl;			//the comeputer's round is the same as player;	
			int r=0,cnum1,cnum2,cnum3,cnum4,cnum5,cnum6,cnum7,cnum8,cnum9,q=0;
			float cnum10=0;
			char flag2;
			char bcard1,bcard2;
			int b[4][13] = {{1,2,3,4,5,6,7,8,9,10,11,12,13},{14,15,16,17,18,19,20,21,22,23,24,25,26},{27,28,29,30,31,32,33,34,35,36,37,38,39},{40,41,42,43,44,45,46,47,48,49,50,51,52}};
			while(r==0){
				cnum1 = rand() * 4 / (RAND_MAX + 1) + 1;
				cnum2 = rand() * 13 / (RAND_MAX + 1) + 1;
				cnum3 = b[cnum1][cnum2];
				cnum4 = rand() * 4 / (RAND_MAX + 1) + 1;
				cnum5 = rand() * 13 / (RAND_MAX + 1) + 1;
				cnum6 = b[cnum4][cnum5];
				switch (cnum3%13){
					case 0: bcard1 = 'A';cnum10+=1;break;
					case 1: bcard1 = '2';cnum10+=2;break;
					case 2: bcard1 = '3';cnum10+=3;break;
					case 3: bcard1 = '4';cnum10+=4;break;
					case 4: bcard1 = '5';cnum10+=5;break;
					case 5: bcard1 = '6';cnum10+=6;break;
					case 6: bcard1 = '7';cnum10+=7;break;
					case 7: bcard1 = '8';cnum10+=8;break;
					case 8: bcard1 = '9';cnum10+=9;break;
					case 9: bcard1 = '0';cnum10+=10;break;
					case 10: bcard1 = 'J';cnum10+=0.5;break;
					case 11: bcard1 = 'Q';cnum10+=0.5;break;
					case 12: bcard1 = 'K';cnum10+=0.5;break;								
				}
				switch (cnum6%13){
					case 0: bcard2 = 'A';cnum10+=1;break;
					case 1: bcard2 = '2';cnum10+=2;break;
					case 2: bcard2 = '3';cnum10+=3;break;
					case 3: bcard2 = '4';cnum10+=4;break;
					case 4: bcard2 = '5';cnum10+=5;break;
					case 5: bcard2 = '6';cnum10+=6;break;
					case 6: bcard2 = '7';cnum10+=7;break;
					case 7: bcard2 = '8';cnum10+=8;break;
					case 8: bcard2 = '9';cnum10+=9;break;
					case 9: bcard2 = '0';cnum10+=10;break;
					case 10: bcard2 = 'J';cnum10+=0.5;break;
					case 11: bcard2 = 'Q';cnum10+=0.5;break;
					case 12: bcard2 = 'K';cnum10+=0.5;break;							
				}
				if ((cnum1 != cnum4)||(bcard1 != bcard2)){
					b[cnum1][cnum2] = -1;
					b[cnum4][cnum5] = -1;
					++r;				
				}
				else continue;		
			}
			cout << "Computer has got the cards:" ;
			switch (cnum1){
				case 1: cout<< "hei tao";break;
				case 2: cout<< "hong tao";break;
				case 3: cout<< "mei hua";break;
				case 4: cout<< "fang kuai";break;}
			if (bcard1=='0') cout << "10" << endl;
			else cout << bcard1 << endl;
			switch (cnum4){
				case 1: cout<< "hei tao";break;
				case 2: cout<< "hong tao";break;
				case 3: cout<< "mei hua";break;
				case 4: cout<< "fang kuai";break;}
			if (bcard2=='0') cout << "10" << endl;
			else cout << bcard1 << endl;
			
			int bcolor[22] = {cnum1,cnum4};
			int bcard[22] ={cnum3%13,cnum6%13};
			int btimes = 2;
			int r1=0;
			while (r1==0){
				cout << "Continue to give poker?(N/Y)" << endl;
				if (cnum10<num10||(cnum10==num10&&btimes<=times)) flag2='Y';
				else if (cnum10>num10||(cnum10==num10&&btimes>times)) flag2='N'; 
			
				if (flag2=='Y'){
					cnum7 = rand() * 4 / (RAND_MAX + 1) + 1;
					cnum8 = rand() * 13 / (RAND_MAX + 1) + 1;
					cnum9 = b[cnum7][cnum8];
					if (cnum9==-1) continue;
					else b[cnum7][cnum8] = -1;
					switch (cnum9%13){
						case 0: cnum10+=1;break;
						case 1: cnum10+=2;break;
						case 2: cnum10+=3;break;
						case 3: cnum10+=4;break;
						case 4: cnum10+=5;break;
						case 5: cnum10+=6;break;
						case 6: cnum10+=7;break;
						case 7: cnum10+=8;break;
						case 8: cnum10+=9;break;
						case 9: cnum10+=10;break;
						case 10: cnum10+=0.5;break;
						case 11: cnum10+=0.5;break;
						case 12: cnum10+=0.5;break;
					}
					bcolor[btimes] = cnum7;
					bcard[btimes] = cnum9%13;
					cout << "Computer has the cards:";
					for (int j=0;j<=btimes;++j){
						switch (bcolor[j]){
							case 1: cout<<"hei tao";break;
					        case 2: cout<<"hong tao";break;
							case 3: cout<<"mei hua";break;
							case 4: cout<<"fang kuai";break;
						}
						switch (bcard[j]){
							case 0: cout<<"A"<< endl;break;
							case 1: cout<<"2"<< endl;break;
							case 2: cout<<"3"<< endl;break;
							case 3: cout<<"4"<< endl;break;
							case 4: cout<<"5"<< endl;break;
							case 5: cout<<"6"<< endl;break;
							case 6: cout<<"7"<< endl;break;
							case 7: cout<<"8"<< endl;break;
							case 8: cout<<"9"<< endl;break;
							case 9: cout<<"10"<< endl;break;
							case 10: cout<<"J"<< endl;break;
							case 11: cout<<"Q"<< endl;break;
							case 12: cout<<"K"<< endl;break;
						}
					}
					++btimes;				
					if (cnum10>21) {cout << "Computer have lost!" << endl;q=2;++r1;flag='N';// jump the while loop for judging whether to continue to select;
					}
				}
				else if (flag2=='N') ++r1;
			}
			// the final judgement;
			if (flag=='Y'||flag=='y'){
				if (p==0&&q==0){
					if (cnum10>num10||(cnum10==num10&&btimes>times)) cout << "The computer win!"<< endl;
					else if(cnum10==num10&&btimes==times) cout << "Equal!" << endl;
					else if(cnum10<num10||(cnum10==num10&&btimes<times))cout << "The player win!" << endl;
					}
				}
			}			
		}
		else if (flag=='N'||flag=='n') break;
		else cout << "Please input Y or N!"<< endl;
		
	}
	return 0;
}


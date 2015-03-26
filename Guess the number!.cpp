//filename:guess the number .cpp
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int num1,num2,num3,num4,num5,num6,num7,num8;       //define int variables
	int i=0,counter=0,win=0,lose=0;					   //assign the value for these int variables
	char flag;										   //judge whether play or not 
	
	srand(time(NULL));								   //initialize random number's seed 	
	while (true) {
		cout << "Are you need to play the game£¿(N/Y)"  << endl;
		cin >> flag;
		
		if (flag=='Y') {                               //generate three different numbers
			while (i==0){							   
				num1 = rand() % 10+1;
				num2 = rand() % 10;
				num3 = rand() % 10;
				if (num1==10) continue;
        		if (num1!=num2 && num2!=num3 && num3!=num1) ++i;
			}

			while (counter<7) {							//guess the number and compare them
				cout << "plese input the number you guess:" << endl;
				cin >> num4 >> num5 >> num6;
	
				int i1=0,i2=0;
	
				if (num1==num4) ++i1;						//calculate A,B for suggestion
					else if (num1==num5||num1==num6) ++i2;
				if (num2==num5) ++i1;
					else if (num2==num4||num2==num6) ++i2;
				if (num3==num6) ++i1;
					else if (num3==num4||num3==num5) ++i2;
	
				num7 = num1*100 + num2*10 + num3;
				num8 = num4*100 + num5*10 + num6;

				if (num7==num8) break; 
				else {
					cout << i1 << 'A' << i2 << 'B' << endl;
					++counter;}
			}
	
			if (counter<7) {											//judge the result and calculate the times of win or lose
				cout << "congratulations!You are right!" << endl;
				++win;												
			}
				else{
					cout << "What a pity,you don't guess it right in limit times,the number is " << num7 <<endl;
					++lose;
				} 
		}
		else break;
	}
	
	cout << "You have played " << win+lose <<"times,win" << win <<"wimes,lose" << lose << "times" << endl;//announce the result
	 
	
	return 0;	 
}

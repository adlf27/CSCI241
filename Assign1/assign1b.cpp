#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tolower;

// function prototypes
int sumOfName(char[],int);
int sumOfDigit(int);
void printTrait(int);

int main()
{
	string input;
	cout << "Numerology Program.\n" << endl;
	do
	{
		int sum1 = 0,sum2 = 0;
		char name[50];

		//asks the user for name
		cout<<"Enter your name: ";
		cin.getline(name, 50);

		//passes name to function and sets the return value to sum1
		sum1 = sumOfName(name, 50);
		sum2 = sumOfDigit(sum1);
		printTrait(sum2);

		//determine wether the users wants to enter anothe name
		cout << "\nDo you want to enter another name(y/n)? ";
		getline(cin, input);


	}while(input == "y"||input=="Y");


	return 0;
}
int sumOfDigit(int digit)
{
	int sum=0;
	while(digit > 0)
	{
		sum += digit % 10;
		digit = digit / 10;
		//if the number has been  fully broken down
		if(0 == digit)
		{
			if(sum>9)
			{
				digit = sum;
				sum = 0;
			}
		}

	}
	return sum;

}


int sumOfName(char name[], int size)
{
	int digit = 0;
	for (unsigned int i=0; name[i]!='\0'; i++)
	{
		name[i] = tolower(name[i]);
		if(! isspace(name[i]))
		{
			digit += (name[i]-'a') +1;
		}
	}
	return digit;
}

void printTrait(int sum)
{
	switch(sum)
	{
	case 0:
		cout << "Your Name Has the traits emptiness, nothingness, blank." << endl;

	break;
	case 1:
		cout << "Your Name Has the traits independence, loneliness, creativity, originally, dominance, leadership, impatience." << endl;

	break;
	case 2:
		cout << "Your Name Has the traits quiet, passive, dioplomatic, co-operation, comforting, soothing, intuitive, compromising, patient." << endl;
	break;
	case 3:
		cout << "Your Name Has the traits charming, outgoing, self expressive, extrovrted, abundance, active, energetic, proud." << endl;
	break;
	case 4:
		cout << "Your Name Has the traits harmony, truth, justice, order, dicipline, practicality." << endl;
	break;
	case 5:
		cout << "Your Name Has the traits new directions, excitment, change, adventure." << endl;
	break;
	case 6:
		cout << "Your Name Has the traits love, harmony, perfection, marriage, tolenrece, public service." << endl;
	break;
	case 7:
		cout << "Your Name Has the traits spirituality, completness, isolation, introspection." << endl;
	break;
	case 8:
		cout << "Your Name Has the traits organization, business, commerce, new beginnings." << endl;
	break;
	case 9:
		cout << "Your Name Has the traits romantic, rebellious, determined, passionate, compassionate." << endl;
	break;
	case 11:
		cout << "Your Name Has the traits idealism, visionary, inspirational." << endl;
	break;
	case 12:
		cout << "Your Name Has the traits perfectionist, discriminating." << endl;
	break;
	case 22:
		cout << "Your Name Has the traits builder, leader, humanitarian, practical, honest." << endl;
	break;

	}
}



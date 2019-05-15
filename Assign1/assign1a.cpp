#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tolower;

int convertName(string name);
void printTrait(int sum);

int main()
{
	string input;
	cout << "Numerology Program.\n" << endl;
	do
	{
		string name;
		int total=0;
//getting the users input
		cout << "Enter your Name: ";
		getline(cin, name);
//calculating the name to a certain number
		total = convertName(name);
//printing the trait that correspond to the users name
		printTrait(total);

		cout << "\nDo you want to enter another name(y/n)? ";
		getline(cin, input);


	}while(input == "y"||input=="Y");


	return 0;
}
//method
int convertName(string name)
{
	int nameResult = 0, sum=0;

	for (unsigned int i=0; i<name.size();i++)
	{
		if(!isspace(name[i]))
		{
			nameResult += tolower( name[i])-'a'+ 1;
		}
 	}
	while(nameResult > 0)
	{
		sum += nameResult % 10;
		nameResult /= 10;
		if(0 == nameResult)
		{
			if(sum>9)
			{
				nameResult = sum;
				sum = 0;
			}
		}
	}

	return sum;
}

//method
void printTrait(int sum)
{
	//updating 2019
	string traits[] = {"Your Name Has the traits emptiness, nothingness, blank.",
                     "Your Name Has the traits independence, loneliness, creativity, originally, dominance, leadership, impatience.",
									   "Your Name Has the traits quiet, passive, dioplomatic, co-operation, comforting, soothing, intuitive, compromising, patient.",
									   "Your Name Has the traits charming, outgoing, self expressive, extrovrted, abundance, active, energetic, proud.",
										 "Your Name Has the traits harmony, truth, justice, order, dicipline, practicality.",
									   "Your Name Has the traits new directions, excitment, change, adventure.",
										 "Your Name Has the traits love, harmony, perfection, marriage, tolenrece, public service.",
										 "Your Name Has the traits spirituality, completness, isolation, introspection.",
									   "Your Name Has the traits organization, business, commerce, new beginnings.",
									   "Your Name Has the traits romantic, rebellious, determined, passionate, compassionate.",
									   "Your Name Has the traits idealism, visionary, inspirational.",
										 "Your Name Has the traits perfectionist, discriminating.",
									   "Your Name Has the traits builder, leader, humanitarian, practical, honest."};
	cout << traits[sum] << endl;

	/*switch(sum)
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
}*/
}

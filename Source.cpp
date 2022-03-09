#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
/*Name:Manlin Mao
Purpose:produce report showing bird sightings for The Kingston Bird Watchers Society*/
using namespace std;
int main() {
	//Housekeeping
	const int SIZE = 20;
	string typeBird[SIZE];
	int numbSightings[SIZE], times, index, avgSightings = 0, totalSightings = 0, noSightingsBelowAvg = 0, mostSeen = 0;

	ofstream fout("birds.dat");
	if (!fout.is_open())
	{
		cout << "Error opening birds.dat";
		system("pause");
		exit(666);
	}
	fout << fixed << setprecision(2);
	fout << right << setw(38) << "Kingston Bird Watchers Society"
		<< endl;
	fout << left << setw(30) << "Type of Bird "
		<< "# of sightings" << endl;
	fout << endl;

	//Loading for loops
	for (times = 0; times < SIZE; times++)
	{
		//Input
		cout << "Enter a type of bird or ^Z to end: ";
		getline(cin, typeBird[times]);
		if (cin.eof())
			break;
		//Validation
		while (typeBird[times].length()==0)
		{
			cout << "Bird type can not be empty, enter again or ^Z to end: ";
			getline(cin, typeBird[times]);
			if (cin.eof())
				break;
		}
		if (cin.eof())
			break;

		//User input
		cout << "Enter numbers of sighting or ^Z to end: ";
		cin >> numbSightings[times];
		
		//Validation
		while (numbSightings[times] < 0 || numbSightings[times]>100 || cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Invalid number of sightings, enter again or ^Z to end: ";
			cin >> numbSightings[times];
			if (cin.eof())
				break;
		}
		totalSightings += numbSightings[times];
		cin.ignore(80, '\n');
	}

	//Caculation
	if (times > 0)
		avgSightings = totalSightings / times;

	for (index = 0; index < times; index++)
	{
		fout << left << setw(42) << typeBird[index]
			<< right << numbSightings[index];

		if (numbSightings[index] < avgSightings)
		{
			fout << "*** below average *** ";
			noSightingsBelowAvg++;
		}
		fout << endl;
		if (numbSightings[index] > numbSightings[mostSeen])
		{
			mostSeen = index;

		}
	}

	fout << endl;
	fout << "Total number of sightings" << setw(19) << totalSightings << endl;
	fout << "The average number of sightings/bird is" << setw(5) << avgSightings << endl;
	fout << "The " << typeBird[mostSeen] << " was seen the most" << endl;

	system("type birds.dat");
	system("pause");
}
/*

*/
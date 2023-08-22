//
// AL Weather Station Data
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include "InterpreterHeader.h"

using namespace std;

int main(void)
{
	// Defining nodes for entire data list
	station_data* root_node, * current_node, * new_node;
	current_node = new station_data;

	current_node->link = NULL;
	root_node = current_node;

	//Defining some necessary variables
	string years_loaded_str = "";
	char user_input_year = ' ';
	char user_input_location = ' ';
	char user_input_type = ' ';
	char repeat = 'Y';


	// Establishing data to be used. Loads requested data.
	do
	{
		ifstream data;

		cout << "Please select which year to load: " << endl;
		cout << "A." << setw(40) << right << "2023 (to August 07)" << endl;

		cin >> user_input_year;

		//put into load_data func
		cout << "\nLoading data..." << endl;
		load_data(user_input_year, data, years_loaded_str);

		// Add new loaded data to linked list
		string dataline;
		getline(data, dataline);
		getline(data, dataline); // Purge first two unnecessary lines in .txt file
		while (!data.eof())
		{
			new_node = new station_data;

			enter_data(*new_node, data);
			//print_data(*new_node, data); //Debugging

			new_node->link = NULL;
			current_node->link = new_node;
			current_node = new_node;
		}

		cout << "\nWould you like to load more years? (Y/N)" << endl;
		cin >> repeat;

		data.close();
	} while (repeat == 'Y');


	// User Input User Input User Input User Input User Input User Input User Input User Input User Input User Input User Input User Input User Input User Input User Input 

	repeat = 'Y';
	cout << "\nAvailable Alabama Weather Station Data from year(s): " << years_loaded_str << endl << endl;
	// Primary while loop. Loads all data procedure functions. Repeats upon user request
	do
	{
		//Defining necessary user input variables
		char user_input_location = ' ';
		char user_input_type = ' ';
		char user_input_time = ' ';

		//Takes location parameter for data
		string user_input_city = "";
		string user_input_station = "";
		cout << "Please select the scope of the data you are looking for: " << endl;
		cout << "A." << setw(60) << right << "Statewide data" << endl;
		cout << "B." << setw(60) << right << "City data" << endl;
		cout << "C." << setw(60) << right << "Station data" << endl << endl;

		cin >> user_input_location;
		if (user_input_location == 'B')
		{
			cout << "\nPlease input specific city in capital letters:" << endl;
			cin >> user_input_city;
		}
		else if (user_input_location == 'C')
		{
			cout << "\nPlease input specific station ID:" << endl;
			cin >> user_input_station;
		}

		// Takes data type parameters
		cout << "\nPlease select the type of data you are looking for: " << endl;
		cout << "A." << setw(60) << right << "Precipitation data" << endl;
		cout << "B." << setw(60) << right << "Temperature data" << endl;
		cout << "C." << setw(60) << right << "Wind data" << endl << endl;

		cin >> user_input_type;
		char user_input_type_stat = ' ';

		char user_input_temperature_maximum_type = ' ';
		char user_input_temperature_minimum_type = ' ';
		char user_input_wind_type = ' ';

		if (user_input_type == 'A') // If user_input_type is precipitation data
		{
			cout << "\nPlease select the specific statistic you are looking for: " << endl;
			cout << "A." << setw(60) << right << "Precipitation amount" << endl;
			cout << "B." << setw(60) << right << "Snow depth" << endl;
			cout << "C." << setw(60) << right << "Snow amount" << endl << endl;

			cin >> user_input_type_stat;
		}
		else if (user_input_type == 'B') // If user_input_type is temperature data
		{
			cout << "\nPlease select the specific statistic you are looking for: " << endl;
			cout << "A." << setw(60) << right << "Average temperature" << endl;
			cout << "B." << setw(60) << right << "Maximum temperature" << endl;
			cout << "C." << setw(60) << right << "Minimum temperature" << endl;

			cin >> user_input_type_stat;

			if (user_input_type_stat == 'B') // If _stat is maximum temperature
			{
				cout << "\nPlease select the specific maximum temperature you are looking for: " << endl;
				cout << "A." << setw(60) << right << "Average maximum temperature" << endl;
				cout << "B." << setw(60) << right << "Absolute maximum temperature" << endl;

				cin >> user_input_temperature_maximum_type;
			}
			if (user_input_type_stat == 'C') // If _stat is minimum temperature
			{
				cout << "\nPlease select the specific minimum temperature you are looking for: " << endl;
				cout << "A." << setw(60) << right << "Average minimum temperature" << endl;
				cout << "B." << setw(60) << right << "Absolute minimum temperature" << endl;

				cin >> user_input_temperature_minimum_type;
			}
		}
		else if (user_input_type == 'C') // If user_input_type is wind data
		{
			cout << "\nPlease select the specific statistic you are looking for: " << endl;
			cout << "A." << setw(60) << right << "Average wind speed" << endl;
			cout << "B." << setw(60) << right << "Fastest 2-minute wind speed" << endl;
			cout << "C." << setw(60) << right << "Fastest 5-second wind speed" << endl;

			cin >> user_input_type_stat;

			if (user_input_type_stat == 'B' || user_input_type_stat == 'C') // If _stat is 2 min wind speed or 5 sec wind speed
			{
				cout << "\nPlease select the type of stat you are looking for: " << endl;
				cout << "A." << setw(60) << right << "Average wind speed for selected interval" << endl;
				cout << "B." << setw(60) << right << "Highest wind speed for selected interval" << endl;

				cin >> user_input_wind_type;
			}
		}


		// Takes date range parameters for data
		cout << "\nPlease select the period of time for the data you are looking for: " << endl;
		cout << "A." << setw(60) << right << "All loaded data" << endl;
		cout << "B." << setw(60) << right << "Specific date range" << endl;
		cout << "C." << setw(60) << right << "Specific day" << endl << endl;

		string user_start_date = "";
		string user_end_date = "";

		cin >> user_input_time;
		if (user_input_time == 'B' || user_input_time == 'C') // If user wishes to specify date range or specific day
		{

			if (user_input_time == 'B') // If user_input_time is specific date range
			{
				cout << "\nPlease input start date in the following format: YYYYMMDD" << endl;
				cin >> user_start_date;

				cout << "\nPlease input end date in the following format: YYYYMMDD" << endl;
				cin >> user_end_date;
			}
			if (user_input_time == 'C') // If user_input_time is specific date
			{
				cout << "\nPlease input specific date in the following format: YYYYMMDD" << endl;
				cin >> user_start_date;
				user_end_date = user_start_date;
			}
		}


		// Program Output Program Output Program Output Program Output Program Output Program Output Program Output Program Output Program Output Program Output Program Output 


		if (user_input_type == 'B' && user_input_type_stat == 'A') { //If user_input_type is temperature data and _stat is average temperature
			cout << "The average temperature with the parameters given is: " <<
				temperature_average(root_node, user_start_date, user_end_date, user_input_station, user_input_city);
		}

		if (user_input_type == 'B' && user_input_type_stat == 'B') { //If user_input_type is temperature data and _stat is maximum temperature
			if (user_input_temperature_maximum_type == 'A') //If maximum_type is average maximum temperature
			{
				cout << "The average maximum temperature is: " <<
					temperature_maximum(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_temperature_maximum_type)
					<< endl << endl;
			}
			else if (user_input_temperature_maximum_type == 'B') //If maximum_type is absolute maximum temperature
			{
				cout << "The absolute maximum temperature is: " <<
					temperature_maximum(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_temperature_maximum_type)
					<< endl << endl;
			}
		}

		if (user_input_type == 'B' && user_input_type_stat == 'C') { //If user_input_type is temperature data and _stat is minimum temperature
			if (user_input_temperature_minimum_type == 'A') //If minimum_type is average minimum temperature
			{
				cout << "The average minimum temperature is: " <<
					temperature_maximum(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_temperature_minimum_type)
					<< endl << endl;
			}
			else if (user_input_temperature_minimum_type == 'B') //If minimum_type is absolute minimum temperature
			{
				cout << "The absolute minimum temperature is: " <<
					temperature_minimum(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_temperature_minimum_type)
					<< endl << endl;
			}
		}

		if (user_input_type == 'A' && user_input_type_stat == 'A') { //If user_input_type is precipitation and _stat is precipitation amount
			cout << "The average precipitation amount with the parameters given is: " <<
				precipitation_amount(root_node, user_start_date, user_end_date, user_input_station, user_input_city)
				<< endl << endl;
		}

		if (user_input_type == 'A' && user_input_type_stat == 'B') { //If user_input_type is precipitation and _stat is snow depth
			cout << "The average snow depth with the parameters given is: " <<
				precipitation_snow_depth(root_node, user_start_date, user_end_date, user_input_station, user_input_city)
				<< endl << endl;
		}

		if (user_input_type == 'A' && user_input_type_stat == 'C') { //If user_input_type is precipitation and _stat is snow amount
			cout << "The average snow amount with the parameters given is: " <<
				precipitation_snow_amount(root_node, user_start_date, user_end_date, user_input_station, user_input_city)
				<< endl << endl;
		}

		if (user_input_type == 'C' && user_input_type_stat == 'A') { //If user_input_type is wind and _stat is wind average
			cout << "The average wind speed for the given parameters is: " <<
				wind_average(root_node, user_start_date, user_end_date, user_input_station, user_input_city)
				<< endl << endl;
		}

		if (user_input_type == 'C' && user_input_type_stat == 'B') { //If user_input_type is wind and _stat is 2 minute wind speed
			if (user_input_wind_type == 'A') //If wind_type is average wind speed
			{
				cout << "The average highest 2 minute wind speed for the given parameters is:" <<
					wind_two_minute(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_wind_type)
					<< endl << endl;
			}
			else if (user_input_wind_type == 'B') //If wind_type is highest wind speed
			{
				cout << "The highest 2 minute wind speed for the given parameters is: " <<
					wind_two_minute(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_wind_type)
					<< endl << endl;
			}
		}

		if (user_input_type == 'C' && user_input_type_stat == 'C') { //If user_input_type is wind and _stat is 5 second wind speed
			if (user_input_wind_type == 'A') //If wind_type is average wind speed
			{
				cout << "The average highest 5 second wind speed for the given parameters is:" <<
					wind_five_second(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_wind_type)
					<< endl << endl;
			}
			else if (user_input_wind_type == 'B') //If wind_type is highest wind speed
			{
				cout << "The highest 5 second wind speed for the given parameters is: " <<
					wind_five_second(root_node, user_start_date, user_end_date, user_input_station, user_input_city, user_input_wind_type)
					<< endl << endl;
			}
		}
		// loop data search?
		cout << "\n\nWould you like to continue to navigate the data and restart the program? (Y/N)" << endl;
		cin >> repeat;

	} while (repeat == 'Y');


	system("pause");
	return 0;
}

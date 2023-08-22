#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

struct station_data {
	string station_id;
	string station_name;
	string date;
	float mdpr;
	float dapr;
	float prcp;
	float snwd;
	float snow;
	float tavg;
	float tmax;
	float tmin;
	float awnd;
	float wsf2;
	float wsf5;

	station_data* link;
};



// Loading data
void load_data(char input, ifstream& file, string& years_loaded); // Opens file for entering into struct node system
void enter_data(station_data& data, ifstream& file); // Enter data to struct node system
void print_data(station_data& data, ifstream& file); // For debug

// Data procedures

// Check data line
bool check_entry(station_data* current_node, string start_date, string end_date, string station_id, string station_name);

// Temp procedures
float temperature_average(station_data* root_node, string start_date, string end_date, string station_id, string station_name);
float temperature_maximum(station_data* root_node, string start_date, string end_date, string station_id, string station_name, char maximum_type);
float temperature_minimum(station_data* root_node, string start_date, string end_date, string station_id, string station_name, char minimum_type);

// Precipitation procedures
float precipitation_amount(station_data* root_node, string start_date, string end_date, string station_id, string station_name);
float precipitation_snow_depth(station_data* root_node, string start_date, string end_date, string station_id, string station_name);
float precipitation_snow_amount(station_data* root_node, string start_date, string end_date, string station_id, string station_name);

// Wind procedures
float wind_average(station_data* root_node, string start_date, string end_date, string station_id, string station_name);
float wind_two_minute(station_data* root_node, string start_date, string end_date, string station_id, string station_name, char type);
float wind_five_second(station_data* root_node, string start_date, string end_date, string station_id, string station_name, char type);

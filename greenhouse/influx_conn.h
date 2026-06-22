#pragma once


void setupInfluxDB();
void sendInfluxDB(float moisture, float lichtwaarde, float air_quality); 
void syncTime();  

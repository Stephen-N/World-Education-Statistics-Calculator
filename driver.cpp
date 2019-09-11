/*************************************************
**  File    :   driver.cpp
**  Project :   Project0, World Education Statistics
**  Author  :   Stephen Ndubueze
**  Date:   :   09/11/19
**  Section :   503
**  E-mail  :   sundubueze78@tamu.edu
**
**  This file contains the main driver program for Project0.
**  Summary: Create ranking of countries with highest literacy
        rates, primary school completion rates, and percent
        GDP spent on education per continent by reading data 
        from txts.
*************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctype.h>
#include "Continent.h"
#include "Country.h"

void readFromFiles(string file1, string file2, vector<Country> vec);
vector<Continent> world;

int main()
{
    string contriesContinentsList = "CountriesContinents.txt";
    string data = "2013WorldBankEducationCensusData.txt";
    vector<Country> kingdoms;

    readFromFiles(contriesContinentsList, data, kingdoms);

    //  TEST: Does continent objects have names
        // string test = "";
        // test = world[0].getContinentName();
        // cout << test << endl;

    //  TEST: Does continent objects have countries
        // test = world[0].getCountries();
        // cout << test << endl;
    
    //  Triggers overload cout to display continent data
    for (unsigned int i = 0; i < world.size(); i++)
    {
        cout << world[i];
    }   
}

void readFromFiles(string file1, string file2, vector<Country> vec)
{
    ifstream fileIn;
    fileIn.open(file1);

    ifstream fileIn2;
    fileIn2.open(file2);
    
    // Reads CountriesContinents.txt and creates list of Continent objects
        //  Checks if file is open
        if (!fileIn.is_open())
        {
            cout << "Error: unable to open file <filename>" << endl;
            return;
        }
        
        string continentCountry;
        fileIn >> continentCountry;

        while(fileIn.eof() == false)
        {
            Continent continent;
            vector<Country> countries;

            //  checks if string is a continent
            if (isupper(continentCountry[1]) == true)
            {
                continent.setContinentName(continentCountry);

                fileIn >> continentCountry;

                // gets rid of symbols and number only entries
                while (isdigit(continentCountry[0]) == true || continentCountry[0] == '-')
                {
                    fileIn >> continentCountry;
                }

                // create list of Country objects for Continent, checks if looking at country
                while (isupper(continentCountry[1]) == false && isdigit(continentCountry[1]) == false && continentCountry[1] != '-')
                {
                    Country country;
                    string temp = continentCountry;
                    // cout << "\t" << continentCountry << endl;
                    country.setName(continentCountry);
                    countries.push_back(country);
                    fileIn >> continentCountry;

                    //  if next continent is found, save previous one in vector
                    if (isupper(continentCountry[1]) == true || temp == continentCountry)
                    {
                        continent.setCountries(countries);
                        world.push_back(continent);
                        break;
                    }
                }
            }
        }
    //

    // Reads WorldBank.txt and gives countries WorldBank data
        //  Checks if file is open
        if (!fileIn2.is_open())
        {
            cout << "Error: unable to open file <filename>2" << endl;
            return;
        }

        string line = "";
        getline(fileIn2, line); //  Skips first line
        int lineCounter = 2;
        
        //  isolates a line from the txt and sorts each data value
        while (getline(fileIn2, line))
        {
            stringstream subLine(line);
            string word;
            int column = 1;
            string countryName = "";
            long int population = 0;
            float adultLitRate = -1;
            float educationGDP = -1;
            float completionRateAll = -1;
            float completionRateMale = -1;
            float completionRateFem = -1;
            float youthLitRateFem = -1;
            float youthLitRateMale = -1;

            while (subLine >> word)
            {
                /*  case # tells the type of data word holds based on the coulumn in txt, ex: case 1 is country name
                    The if statement ensures data is passed when all coulmn data is recorded
                */
                switch (column)
                {
                    case 1:
                        countryName = word;
                        // cout << "\tcountry name: " << countryName << endl;
                        break;
                    case 2:
                        population = stol(word);
                        // cout << "\tpopulation: " << population << endl;
                        break;
                    case 3:
                        if (word == "N/A")
                        {
                            // cout << "\tadultLitRate: N/A" << endl;
                        }
                        else
                        {
                            adultLitRate = stof(word);
                            // cout << "\tadultLitRate: " << adultLitRate << endl;
                        }
                        
                        break;
                    case 4:
                        if (word == "N/A")
                        {
                            // cout << "\teducationGDP: N/A" << endl;
                        }
                        else
                        {
                            educationGDP = stof(word);
                            // cout << "\teducationGDP: " << educationGDP << endl;
                        }   
                        
                        break;
                    case 5:
                        if (word == "N/A")
                        {
                            // cout << "\tcompletionRateAll: N/A" << endl;
                        }
                        else
                        {
                            completionRateAll = stof(word);
                            // cout << "\tcompletionRateAll: " << completionRateAll << endl;
                        }
                        
                        break;
                    case 6:
                        if (word == "N/A")
                        {
                            // cout << "\teducationGDP: N/A" << endl;
                        }
                        else
                        {
                            completionRateMale = stof(word);
                            // cout << "\tcompletionRateMale: " << completionRateMale << endl;
                        }
                        
                        break;
                    case 7:
                        if (word == "N/A")
                        {
                            // cout << "\teducationGDP: N/A" << endl;
                        }
                        else
                        {
                            completionRateFem = stof(word);
                            // cout << "\tcompletionRateFem: " << completionRateFem << endl;
                        }
                        
                        break;
                    case 8:
                        if (word == "N/A")
                        {
                            // cout << "\teducationGDP: N/A" << endl;
                        }
                        else
                        {
                            youthLitRateFem = stof(word);
                            // cout << "\tyouthLitRateFem: " << youthLitRateFem << endl;
                        }
                        
                        break;
                    case 9:
                        if (word == "N/A")
                        {
                            // cout << "\teducationGDP: N/A" << endl;
                        }
                        else
                        {
                            youthLitRateMale = stof(word);
                            // cout << "\tyouthLitRateMale: " << youthLitRateMale << endl;
                        }
                        
                        break;
                    default:
                        cout << "Error has occurred" << endl;
                        break;
                }
                
                //  Give data to country object in respective Continent
                if (column == 9)
                {
                    for (unsigned int i = 0; i < world.size(); i++)
                    {
                        string continentCountryList = world[i].getCountries();
                        istringstream realList (continentCountryList);
                        string countryInList = "";

                        while (realList >> countryInList) 
                        {           
                            //  Confirms which continent country is in Continent and adds data
                            if (countryName == countryInList)
                            {
                                world[i].setCountryData(countryName, population, adultLitRate, educationGDP, 
                                    completionRateAll, completionRateMale, completionRateFem,
                                    youthLitRateFem, youthLitRateMale);              
                            }
                        } 
                    }
                }
                
            
                column++;
            }

            lineCounter++;
        }
    //
}
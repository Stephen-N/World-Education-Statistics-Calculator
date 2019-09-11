/*************************************************
**  Name: Continent.cpp
**  constructs values for member variables and returns them
**  prints continent data
*************************************************/
#include <iostream>
#include "Continent.h"
#include "Country.h"

//  SETTERS
void Continent::setCountries(const vector<Country> continentCountries)
{
    countriesInContinent = continentCountries;
}

void Continent::setHighestPopulation (Country countryPop)
{
    if (countryPop.getPopulation() > highestPopulation.getPopulation())
    {
        highestPopulation = countryPop;
    }
}

void Continent::setHighestGDPSpent (Country countryGDP)
{
    if (countryGDP.getEducationGDPSpent() > highestGDPSpent.getEducationGDPSpent())
    {
        highestGDPSpent = countryGDP;
    }
}

void Continent::setHighestLiteracyRate (Country countryLitRate)
{
    if (countryLitRate.getLiteracyRate() > highestLiteracyRate.getLiteracyRate())
    {
        highestLiteracyRate = countryLitRate;
    }
    
}

void Continent::setContinentName (string continentName)
{
    name = continentName;
}

void Continent::setCountryData (string countryName, long int population, float adultLitRate, float educationGDP, 
            float completionRateAll, float completionRateMale, float completionRateFem,
            float youthLitRateFem, float youthLitRateMale)
{
    //  Finds right country object and assigns passed in values
    for (unsigned int i = 0; i < countriesInContinent.size(); i++)
    {
        if (countryName == countriesInContinent[i].getName())
        {
            countriesInContinent[i].setPopulation(population);
            countriesInContinent[i].setLiteracyRate(adultLitRate);
            countriesInContinent[i].setEducationGDPSpent(educationGDP);
            countriesInContinent[i].setPrimaryCompletionFemale(completionRateAll);
            countriesInContinent[i].setPrimaryCompletionMale(completionRateMale);
            countriesInContinent[i].setPrimaryCompletionAll(completionRateFem);
            countriesInContinent[i].setYouthLitRateFem(youthLitRateFem);
            countriesInContinent[i].setYouthLitRateMale(youthLitRateMale);
        
            setHighestLiteracyRate(countriesInContinent[i]);
            setHighestGDPSpent(countriesInContinent[i]);
            setHighestPopulation(countriesInContinent[i]);
        }
        
    }
    
}

//  GETTERS
string Continent::getCountries () const
{
    string listOfCountries = "";

    for (unsigned int i = 0; i < countriesInContinent.size(); i++)
    {
        listOfCountries.append(countriesInContinent[i].getName() + " ");
    }

    return listOfCountries;
}

long int Continent::getPopulation () const
{
    long int sum = 0;

    for (unsigned int i = 0; i < countriesInContinent.size(); i++)
    {
        sum = sum + countriesInContinent[i].getPopulation();
    } 
    
    return sum;
}

Country Continent::getHighestLiteracyRate () const
{ 
    return highestLiteracyRate;
}

Country Continent::getHighestGDP () const
{
    return highestGDPSpent;
}

Country Continent::getHighestPopulation () const
{
    return highestPopulation;
}

string Continent::getContinentName () const
{
    return name;
}

// OVERLOAD: new country object is created to access country member functions and readability
std::ostream& operator<<(std::ostream& os, const Continent c)
{
    os << c.getContinentName() << endl;
    os << "Population: " << c.getPopulation() << endl;

    Country country = c.getHighestLiteracyRate();
    os << "Country with highest literacy rate: " << country.getName() 
        << " with a population of " << country.getPopulation() 
        << " and a literacy rate of " << country.getLiteracyRate() << endl;

    country = c.getHighestGDP();
    os << "Country with highest GDP expenditure on education: " << country.getName()
        << " with a population of " << country.getPopulation() 
        << " and a literacy rate of " << country.getLiteracyRate() << endl;
    
    country = c.getHighestPopulation();
    os << "Country with highest population: "  << country.getName()
        << " with a population of " << country.getPopulation() 
        << " and a literacy rate of " << country.getLiteracyRate() << endl;

    return os;
}
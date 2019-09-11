/*************************************************
**  Name: Continent.h
**  Child Class of Country
**  handles printing of data and sorting countries
*************************************************/
#ifndef Continent_H
#define Continent_H

#include "Country.h"
#include <vector>
#include <string>

class Continent : public Country
{
    private:
        vector<Country> countriesInContinent;
        Country highestPopulation;
        Country highestGDPSpent;
        Country highestLiteracyRate;
        string name = "";
    public:
        //  SETTERS
        void setCountries (const vector<Country> continentCountries);
        void setHighestPopulation (Country countryPop);
        void setHighestGDPSpent (Country countryGDP);
        void setHighestLiteracyRate (Country countryLitRate);
        void setContinentName (string continentName);
        void setCountryData (string countryName, long int population, float adultLitRate, float educationGDP, 
            float completionRateAll, float completionRateMale, float completionRateFem,
            float youthLitRateFem, float youthLitRateMale);

        //  GETTERS
        string getCountries () const;
        long int getPopulation () const;
        Country getHighestLiteracyRate () const;
        Country getHighestGDP () const;
        Country getHighestPopulation () const;
        string getContinentName() const;

};

// OVERLOAD
std::ostream& operator<<(std::ostream& os, const Continent c);

#endif
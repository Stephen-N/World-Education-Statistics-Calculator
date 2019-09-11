/*************************************************
**  Name: Country.h
**  Parent Class of Continent
**  declares member functions for country.cpp
*************************************************/
#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

class Country
{
    private:
        string name = "";
        long int population = 0;
        float literacyRate = 0;
        float educationGDPSpent = 0;
        float primaryCompletionFemale = 0;
        float primaryCompletionMale = 0;
        float primaryCompletionTotal = 0;
        float youthLitRateFem = 0;
        float youthLitRateMale = 0;

    public:
        //  Setters
        void setName (const string countryName);
        void setPopulation (const long int countryPop);
        void setLiteracyRate (const float litRate);
        void setEducationGDPSpent (const float GDPSpent);
        void setPrimaryCompletionFemale (const float completeFemale);
        void setPrimaryCompletionMale (const float completeMale);
        void setPrimaryCompletionAll (const float completeAll);
        void setYouthLitRateFem (const float litRateFem);
        void setYouthLitRateMale (const float litRateMale);

        //  Getters
        string getName() const;
        long int getPopulation() const;
        float getEducationGDPSpent() const;
        float getLiteracyRate() const;
        float getPrimaryFemale() const;
        float getPrimaryCompletionMale() const;
        float getPrimaryCompletionAll() const;
        float getLitRateFem() const;
        float getLitRateMale() const;

        //  OVERLOAD
        Country& operator=(const Country &c);

};

#endif
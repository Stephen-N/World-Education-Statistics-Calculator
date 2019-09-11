/*************************************************
**  Name: Country.cpp
**  constructs values for member variables and returns them
*************************************************/
#include <iostream>
#include <string>
#include "Country.h"

//  SETTERS
    void Country::setName (const string countryName) { name = countryName; }

    void Country::setPopulation (const long int countryPop) { population = countryPop; }

    void Country::setLiteracyRate (const float litRate) { literacyRate = litRate; }

    void Country::setEducationGDPSpent (const float GDPSpent) { educationGDPSpent = GDPSpent; }

    void Country::setPrimaryCompletionFemale (const float completeFemale) { primaryCompletionFemale = completeFemale; }

    void Country::setPrimaryCompletionMale (const float completeMale) { primaryCompletionMale = completeMale; }
    
    void Country::setPrimaryCompletionAll (const float completeAll) { primaryCompletionTotal = completeAll; }

    void Country::setYouthLitRateFem (const float litRateFem) { youthLitRateFem = litRateFem; }

    void Country::setYouthLitRateMale (const float litRateMale) { youthLitRateMale = litRateMale; }

//  GETTERS
    string Country::getName() const { return name; }
    
    long int Country::getPopulation() const { return population; }

    float Country::getLiteracyRate() const { return literacyRate; }
    
    float Country::getEducationGDPSpent() const { return educationGDPSpent; }

    float Country::getPrimaryFemale() const { return primaryCompletionFemale; }

    float Country::getPrimaryCompletionMale() const { return primaryCompletionMale; }
    
    float Country::getPrimaryCompletionAll() const { return primaryCompletionTotal; }
    
    float Country::getLitRateFem() const { return youthLitRateFem; }

    float Country::getLitRateMale() const { return youthLitRateMale; }

//  OVERLOAD
    Country& Country::operator=(const Country &c)
    {
        name = c.getName();
        population = c.getPopulation();
        literacyRate = c.getLiteracyRate();
        educationGDPSpent = c.getEducationGDPSpent();
        primaryCompletionFemale = c.getPrimaryFemale();
        primaryCompletionMale = c.getPrimaryCompletionMale();
        primaryCompletionTotal = c.getPrimaryCompletionAll();
        youthLitRateFem = c.getLitRateFem();
        youthLitRateMale = c.getLitRateMale();

        return *this;
    }

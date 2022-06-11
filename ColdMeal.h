#ifndef COLDMEAL_H
#define COLDMEAL_H

#include "Recipe.h"

class ColdMeal : public Recipe
{
private:
	double storingTemperature; // supposed to belong to the interval (-18 ; 4)
public:
	ColdMeal(const MyString& name, const size_t& preparationTime, const MyString& instructions, const double& storingTemperature);
	void print() const override;
	Recipe* clone() const override;

	void setStoringTemperature(const double& storingTemperature);
	const double getStoringTemperature() const;
};

#endif
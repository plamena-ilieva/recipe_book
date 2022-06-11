#ifndef RECIPE_H
#define RECIPE_H

#include <time.h>
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"

typedef Vector<Pair<MyString, size_t>> IngredientList;
class Recipe
{
private:
	MyString name;
	IngredientList ingredients;
	size_t preparationTime;
	MyString instructions;
	Vector<size_t> ratings;
	double averageRating;
	int ID;
	//size_t difficulty; // (1-2 for cold meals, 3-5 for hot meals) ??

public:

	Recipe(const MyString& name, const size_t& preparationTime, const MyString& instructions);
	virtual ~Recipe() = default;
	virtual void print() const;
	virtual Recipe* clone() const = 0;


	void setName(const MyString& name);
	void setIngredients(const IngredientList& ingredients);
	void setPreparationTime(const size_t& time);
	void setInstructions(const MyString& instructions);
	void setRandomID();
	void setInitialRatingState();
	

	void addRating(const size_t& rating); // not supposed to be used in the initialization

	const MyString getName() const;
	const IngredientList getIngredients() const;
	const size_t getPreparationTime() const;
	const MyString getInstructions() const;
	const int getID() const;
	const double getRating() const;

	void inputIngredients(); // !! A function to take user input for the ingredients list
};

#endif
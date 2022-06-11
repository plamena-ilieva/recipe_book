#ifndef HOTMEAL_H
#define HOTMEAL_H
#include "Recipe.h"

class HotMeal : public Recipe
{
private:
	size_t cookingTemperature; // ranging from 90 to 260 Celsius
	size_t cookingTime;// time necessary for the meal to be cooked (boiled, fried, baked, roasted, etc.)
	Vector<MyString> appliances; // list of necessary appliances in order to execute the recipe (stove, oven, mixer, etc.)
public:
	HotMeal(const MyString& name, const size_t& preparationTime, const MyString& instructions, const size_t& cookingTemperature, const size_t& cookingTime);
	void print() const override;
	Recipe* clone() const override;

	void setCookingTemperature(const size_t& cookingTemperature);
	void setCookingTime(const size_t& cookingTime);
	void setAppliances(const Vector<MyString> appliances);

	const size_t getCookingTemperature() const;
	const size_t getCookingTime() const;
	const Vector<MyString> getAppliances() const;

	void inputAppliances(); // !! A function to take user input for appliances list
};

#endif

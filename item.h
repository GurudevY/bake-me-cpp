#ifndef ITEM_H
#define ITEM_H
#include "ingredient.h"

 #include <string>
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>


class Item
{
    public:

        void addItem();
        void updateItem();
        void deleteItem();
        void bakeItem();
        void viewItem();

        void setIngredient(vector<Ingredient> c_it);
        void setItemName(string c_name);
        void setTime(double c_time);
        void setCost(double c_cost);
        void setTemp(double c_temp);
        void setItemCalorie(double c_cal);

        vector<Ingredient> getIngredients();
        string getName();
        double getCost();
        double getTemp();
        double getCalorie();
        double getTime();

        void write_file(vector<Ingredient>& it);

    protected:

    private:
        string item_name;
        vector<Ingredient> it;
        double time;
        double temp;
        double item_calorie;
        double cost;

};

#endif // ITEM_H

#ifndef INGREDIENT_H
#define INGREDIENT_H
 #include <string>
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>

using namespace std;

class Ingredient
{
    public:
        Ingredient();
        Ingredient(string str,vector <string>& details,Ingredient& in);
        void setName(string c_name);
        void setShapes(vector<string> c_shapes);
        void setQuantity(double c_quantity);
        void setCalorie(double c_calorie);
        void setPrice(double c_price);
        void write_file(Ingredient& obj,string path);
        string getName();
        vector <string> getShapes();
        double getQuantity();
        double getCalorie();
        double getPrice();
        void display();

    protected:

    private:
        string name;
        vector <string> shapes;
        double quantity;
        double calorie;
        double price;

};

#endif // INGREDIENT_H

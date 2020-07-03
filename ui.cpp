#include "ui.h"
#include "ingredient.h"

#include <string>
#include <vector>
#include <conio.h>
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <cstdlib>
namespace
{
    Ingredient ing;
    Item it;
    vector<Ingredient> ing_vec;
    vector<Ingredient> c_it;
    string path = "test.txt";
} // namespace

string c_name;
vector<string> c_shapes;
vector<string> shapes;
double c_quantity;
double c_calorie;
double c_price;
Ingredient UI::addIngredient()
{
    cout << "\t\t\tEnter the name of the Ingredient: ";
    cin.sync();
    getline(cin, c_name);
    ing.setName(c_name);
    int shapesCount;
    cout << "\t\t\tEnter the  number of Shapes to the Ingredient: ";
    cin >> shapesCount;
    string shape;
    for (int i = 0; i < shapesCount; i++)
    {
        cout << "\t\t\tEnter the shape number " << i + 1 << " : ";
        cin.sync();
        getline(cin, shape);
        c_shapes.push_back(shape);
    }
    ing.setShapes(c_shapes);
    cout << "\t\t\tEnter the quantity in grams of the Ingredient: ";
    cin >> c_quantity;
    ing.setQuantity(c_quantity);
    cout << "\t\t\tEnter the calorie/unit of the Ingredient: ";
    cin >> c_calorie;
    ing.setCalorie(c_calorie);
    cout << "\t\t\tEnter the price/unit of the Ingredient: ";
    cin >> c_price;
    ing.setPrice(c_price);

    return ing;
}
void UI::updateIngredient(vector<Ingredient> &ing_vec)
{

    //getting details
    int chu;
    cout << "\n\n\t\t\t===========================================\n";
    cout << "\t\t\t| 1 . Update all details of the ingredient|" << endl;
    cout << "\t\t\t| 2 . Update name of the ingredient       |" << endl;
    cout << "\t\t\t| 3 . Update shapes of the ingredient     |" << endl;
    cout << "\t\t\t| 4 . Update quantity of the ingredient   |" << endl;
    cout << "\t\t\t| 5 . Update calorie of the ingredient    |" << endl;
    cout << "\t\t\t| 6 . Update price of the ingredient      |" << endl;
    cout << "\t\t\t===========================================\n";
    cout << "\t\t\t  Enter a choice: ";
    cin >> chu;
    cout << endl
         << endl;
    //switch cases for updations

    switch (chu)
    {
    case 1:
    {
    }
    break;
    case 2:
    {
    }
    break;
    case 3:
    {
        updateShapes(ing_vec);
    }
    break;
    case 4:
    {
        updateQuantity(ing_vec);
    }
    break;
    case 5:
    {
        updateCalorie(ing_vec);
    }
    break;
    case 6:
    {
        updatePrice(ing_vec);
    }
    break;
    default:
    {
    }
    break;
    }
}

void UI::updateQuantity(vector<Ingredient> &ing_vec)
{
    string up_name;
    int ch_ing;
    double up_quantity;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t        Ingredients list          " << endl;
    cout << "\t\t\t----------------------------------" << endl;
    int i = 0;
    for (auto &itr : ing_vec)
    {

        string namez;
        namez = itr.getName();
        cout << "\t\t\t\t\t" << i + 1 << ": " << namez << endl;
        i++;
    }
    cout << "\t\t\tEnter the choice of the Ingredient to be updated: ";
    cin >> ch_ing;

    //Selecting the line
    string oldstr, line3;
    ifstream upfile("test.txt");
    upfile.seekg(ios::beg);
    for (int i = 0; i < ch_ing - 1; ++i)
    {

        upfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(upfile, oldstr);
    upfile.close();

    //Selecting the line
    string newname;
    string newshapes;
    vector<string> newshp;
    double newquantity;
    double newcalorie;
    double newprice;
    vector<Ingredient>::iterator j;
    int n = 0;
    for (j = ing_vec.begin(); j != ing_vec.end(); ++j)
    {
        if (n = (ch_ing - 1))
        {
            ing_vec[n].display();
            ing.setName(ing_vec[n].getName());
            ing.setShapes(ing_vec[n].getShapes());
            ing.setCalorie(ing_vec[n].getCalorie());
            ing.setPrice(ing_vec[n].getPrice());
            ing_vec.erase(j + n);
            break;
        }
        n++;
    }
    cout << "\t\t\tEnter the new quantity of Ingredient to be updated: ";
    cin >> up_quantity;
    newquantity = up_quantity;
    ing.setQuantity(newquantity);
    ing_vec.push_back(ing);

    /**
           Removing the line from file
             */
    ifstream fin;
    fin.open("test.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line3))
    {
        istringstream iss_line(line3);

        while (getline(iss_line, line3))
        {
            if (line3 != oldstr)
            {
                temp << line3 << endl;
            }
        }
    }
    fin.close();
    temp.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");
    /**

           Removing the line from file
             */
    ing.write_file(ing, path);
    //  return ing;
}
void UI::updateShapes(vector<Ingredient> &ing_vec)
{
    string up_name;
    int ch_ing;
    double up_quantity;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t        Ingredients list          " << endl;
    cout << "\t\t\t----------------------------------" << endl;
    int i = 0;
    for (auto &itr : ing_vec)
    {

        string namez;
        namez = itr.getName();
        cout << "\t\t\t\t\t" << i + 1 << ": " << namez << endl;
        i++;
    }
    cout << "\t\t\tEnter the choice of the Ingredient to be updated: ";
    cin >> ch_ing;

    //Selecting the line
    string oldstr, line3;
    ifstream upfile("test.txt");
    upfile.seekg(ios::beg);
    for (unsigned int i = 0; i < ch_ing - 1; ++i)
    {

        upfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(upfile, oldstr);
    upfile.close();

    //Selecting the line
    /** \brief
             *
             * \param
             * \param
             * \return
             *
             */
    vector<Ingredient>::iterator j;
    int n = 0;
    vector<string> oldShapes;
    for (j = ing_vec.begin(); j != ing_vec.end(); ++j)
    {
        if (n = ch_ing - 1)
        {
            ing_vec[n].display();
            ing.setName(ing_vec[n].getName());
            ing.setQuantity(ing_vec[n].getQuantity());
            oldShapes = ing_vec[n].getShapes();
            ing.setCalorie(ing_vec[n].getCalorie());
            ing.setPrice(ing_vec[n].getPrice());
            ing_vec.erase(j + n);
            break;
        }
        n++;
    }
    int chu;
    cout << "\n\n\t\t\t===========================================\n";
    cout << "\t\t\t|    1 . Add shapes to the list           |" << endl;
    cout << "\t\t\t|    2 . Remove shape from the list       |" << endl;
    cout << "\t\t\t===========================================\n";
    cout << "\t\t\t  Enter a choice: ";
    cin >> chu;
    cout << endl
         << endl;

    switch (chu)
    {

    case 1:
    {
        vector<string> addShape;
        int cnt;
        cout << "\t\t\tEnter the  number of Shapes to be added: ";
        cin >> cnt;
        string newshapez;
        for (int i = 0; i < cnt; i++)
        {
            cout << "\t\t\tEnter the shape number " << i + 1 << " : ";
            cin.sync();
            getline(cin, newshapez);
            addShape.push_back(newshapez);
        }

        for (int f = 0; f < addShape.size(); f++)
        {
            oldShapes.push_back(addShape.at(f));
        }
        ing.setShapes(oldShapes);
    }
    break;
    case 2:
    {
        for (int h = 0; h < oldShapes.size(); h++)
        {
            cout << "\t\t\t\t" << h + 1 << ": " << oldShapes[h] << endl;
        }
        int ch_del;
        cout << "\t\t\tEnter the  shape number to be deleted: ";
        cin >> ch_del;
        vector<string>::iterator s;
        int m = 0;
        for (s = oldShapes.begin(); s != oldShapes.end(); ++s)
        {
            if (m = ch_del - 1)
            {
                oldShapes.erase(s + m);
                break;
            }
            m++;
        }
        ing.setShapes(oldShapes);
    }
    break;
    default:
        cout << "\t\t\t-----------Valid Choice Pls-----------" << endl;
        break;
    }
    ing_vec.push_back(ing);

    /**
           Removing the line from file
             */
    ifstream fin;
    fin.open("test.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line3))
    {
        istringstream iss_line(line3);

        while (getline(iss_line, line3))
        {
            if (line3 != oldstr)
            {
                temp << line3 << endl;
            }
        }
    }
    fin.close();
    temp.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");
    /**

           Removing the line from file
             */
    ing.write_file(ing, path);
}
void UI::updateCalorie(vector<Ingredient> &ing_vec)
{
    string up_name;
    int ch_ing;
    double up_calorie;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t        Ingredients list          " << endl;
    cout << "\t\t\t----------------------------------" << endl;
    int i = 0;
    for (auto &itr : ing_vec)
    {

        string namez;
        namez = itr.getName();
        cout << "\t\t\t\t\t" << i + 1 << ": " << namez << endl;
        i++;
    }
    cout << "\t\t\tEnter the choice of the Ingredient to be updated: ";
    cin >> ch_ing;

    //Selecting the line
    string oldstr, line3;
    ifstream upfile("test.txt");
    upfile.seekg(ios::beg);
    for (unsigned int i = 0; i < ch_ing - 1; ++i)
    {

        upfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(upfile, oldstr);
    upfile.close();

    //Selecting the line
    string newname;
    string newshapes;
    vector<string> newshp;
    double newquantity;
    double newcalorie;
    double newprice;
    vector<Ingredient>::iterator j;
    int n = 0;
    for (j = ing_vec.begin(); j != ing_vec.end(); ++j)
    {
        if (n = ch_ing - 1)
        {
            ing_vec[n].display();
            ing.setName(ing_vec[n].getName());
            ing.setShapes(ing_vec[n].getShapes());
            ing.setQuantity(ing_vec[n].getQuantity());
            ing.setPrice(ing_vec[n].getPrice());
            ing_vec.erase(j + n);
            break;
        }
        n++;
    }
    cout << "\t\t\tEnter the new calorie of Ingredient to be updated: ";
    cin >> up_calorie;
    newcalorie = up_calorie;
    ing.setQuantity(newcalorie);
    ing_vec.push_back(ing);

    /**
           Removing the line from file
             */
    ifstream fin;
    fin.open("test.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line3))
    {
        istringstream iss_line(line3);

        while (getline(iss_line, line3))
        {
            if (line3 != oldstr)
            {
                temp << line3 << endl;
            }
        }
    }
    fin.close();
    temp.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");
    /**

           Removing the line from file
             */
    ing.write_file(ing, path);
}
void UI::updatePrice(vector<Ingredient> &ing_vec)
{
    string up_name;
    int ch_ing;
    double up_price;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t        Ingredients list          " << endl;
    cout << "\t\t\t----------------------------------" << endl;
    int i = 0;
    for (auto &itr : ing_vec)
    {

        string namez;
        namez = itr.getName();
        cout << "\t\t\t\t\t" << i + 1 << ": " << namez << endl;
        i++;
    }
    cout << "\t\t\tEnter the choice of the Ingredient to be updated: ";
    cin >> ch_ing;

    //Selecting the line
    string oldstr, line3;
    ifstream upfile("test.txt");
    upfile.seekg(ios::beg);
    for (unsigned int i = 0; i < ch_ing - 1; ++i)
    {

        upfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(upfile, oldstr);
    upfile.close();

    //Selecting the line
    string newname;
    string newshapes;
    vector<string> newshp;
    double newquantity;
    double newcalorie;
    double newprice;
    vector<Ingredient>::iterator j;
    int n = 0;
    for (j = ing_vec.begin(); j != ing_vec.end(); ++j)
    {
        if (n = ch_ing - 1)
        {
            ing_vec[n].display();
            ing.setName(ing_vec[n].getName());
            ing.setShapes(ing_vec[n].getShapes());
            ing.setCalorie(ing_vec[n].getCalorie());
            ing.setQuantity(ing_vec[n].getQuantity());
            ing_vec.erase(j + n);
            break;
        }
        n++;
    }
    cout << "\t\t\tEnter the new price of Ingredient to be updated: ";
    cin >> up_price;
    newprice = up_price;
    ing.setPrice(newprice);
    ing_vec.push_back(ing);

    /**
           Removing the line from file
             */
    ifstream fin;
    fin.open("test.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line3))
    {
        istringstream iss_line(line3);

        while (getline(iss_line, line3))
        {
            if (line3 != oldstr)
            {
                temp << line3 << endl;
            }
        }
    }
    fin.close();
    temp.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");
    /**

           Removing the line from file
             */
    ing.write_file(ing, path);
}
void UI::deleteIngredient(vector<Ingredient> &ing_vec)
{
    string up_name;
    int ch_ing;
    double up_quantity;
    cout << "\t\t\t----------------------------------" << endl;
    cout << "\t\t\t        Ingredients list          " << endl;
    cout << "\t\t\t----------------------------------" << endl;
    int i = 0;
    for (auto &itr : ing_vec)
    {

        string namez;
        namez = itr.getName();
        cout << "\t\t\t\t\t" << i + 1 << ": " << namez << endl;
        i++;
    }
    cout << "\t\t\tEnter the choice of the Ingredient to be deleted: ";
    cin >> ch_ing;

    //Selecting the line
    string oldstr, line3;
    ifstream upfile("test.txt");
    upfile.seekg(ios::beg);
    for (unsigned int i = 0; i < ch_ing - 1; ++i)
    {

        upfile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    getline(upfile, oldstr);
    upfile.close();

    //Selecting the line

    //erasing the obj from vector
    vector<Ingredient>::iterator j;
    int n = 0;
    for (j = ing_vec.begin(); j != ing_vec.end(); ++j)
    {
        if (n = ch_ing - 1)
        {
            ing_vec[n].display();
            ing_vec.erase(j + n);
            break;
        }
        n++;
    }
    //erasing the obj from vector

    /**
           Removing the line from file
             */
    ifstream fin;
    fin.open("test.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(fin, line3))
    {
        istringstream iss_line(line3);

        while (getline(iss_line, line3))
        {
            if (line3 != oldstr)
            {
                temp << line3 << endl;
            }
        }
    }
    fin.close();
    temp.close();
    remove("test.txt");
    rename("temp.txt", "test.txt");
    /**

           Removing the line from file
             */
}

Item UI::addItem(vector<Ingredient> &ing_vec)
{
    vector<Ingredient> ing2;
    ing2 = ing_vec;
    int wh = 1;
    string c_item_name;
    cout << "\t\t\tEnter the Name of the Item ";
    cin.sync();
    getline(cin, c_item_name);
    double d_price = 0, d_cal = 0;
    while (wh)
    {

        system("cls");
        cout << "\n\n\t\t\t =================================================================\n";
        cout << "\t\t\t  1 . Add Ingredients  to the Item" << endl;
        cout << "\t\t\t  2 . View details and EXIT " << endl;
        cout << "\t\t\t =================================================================\n";
    heres:
        cout << "\t\t\t  Enter a choice: ";
        char ch;
        cin >> ch;
        if (ch > 57 || ch < 48)
        {
            cout << "\t\t\tPlease enter a valid choice [1/2]. : " << endl;
            goto heres;
        }
        cout << endl
             << endl;

        switch (ch)
        {
        case '1':
        {

            int i = 0, ch_it;
            for (auto &itr : ing2)
            {
                string namez;
                if (itr.getQuantity() > 0)
                {
                    namez = itr.getName();
                    cout << "\t\t\t\t\t" << i + 1 << ": " << namez << endl;
                }
                i++;
            }
            cout << "\t\t\tEnter the choice of the Ingredient to be updated: ";
            cin >> ch_it;
            ch_it--;

            ing2[ch_it].display();
            double limit, input;
            limit = ing2[ch_it].getQuantity();
        itQ:
            cout << "\t\t\tEnter the quantity of " << ing_vec[ch_it].getName() << " in gms :";
            cin >> input;
            cout << endl;
            if (input > limit)
            {
                cout << "\t\t\tEntered Quantity exceeds available stock " << endl
                     << endl;
                goto itQ;
            }
            else
            {
                ing2[ch_it].setQuantity(limit - input);
            }
            d_price += input * (ing2[ch_it].getPrice());
            d_cal += input * (ing2[ch_it].getCalorie());
            cout << "Cal: " << d_cal << endl;
            cout << "Price: " << d_price << endl;
            c_it.push_back(ing2[ch_it]);
            it.setCost(d_price);
            it.setItemCalorie(d_cal);
            getch();
        }

        break;
        case '2':
        {
            double c_time, c_temp;
            cout << "\t\t\tEnter the baking time in minutes : ";
            cin >> c_time;
            cout << endl;
            cout << "\t\t\tEnter the baking temperature in *C : ";
            cin >> c_temp;
            cout << endl;
            it.setItemName(c_item_name);
            it.setIngredient(c_it);
            it.setTime(c_time);
            it.setTemp(c_temp);
            it.setItemCalorie(d_cal);

            wh = 0;
        }
        break;
        default:
            cout << "\t\t\tPlease enter a valid choice [1/2].  " << endl;
        }
    }

    c_it.clear();
    return it;
}

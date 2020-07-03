#include "item.h"
#include "ingredient.h"

 #include <string>
 #include <vector>
 #include <iostream>
 #include <stdlib.h>
 #include <bits/stdc++.h>
 #include <fstream>
 #include <sstream>
 #include <cstdlib>

void Item::setItemName(string c_name)
{
    item_name=c_name;
}
void Item::setIngredient(vector <Ingredient> c_it)
{
    it=c_it;
}
void Item::setTime(double c_time)
{
    time=c_time;
}
void Item::setCost(double c_cost)
{
    cost=c_cost;
}
void Item::setTemp(double c_temp)
{
    temp=c_temp;
}
void Item::setItemCalorie(double c_cal)
{
    item_calorie=c_cal;
}
vector<Ingredient> Item::getIngredients()
{
    return it;
}

double Item::getCost()
{
    return cost;
}
double Item::getTime()
{
    return time;
}
double Item::getCalorie()
{
    return item_calorie;
}
string Item::getName()
{
    return item_name;
}

void Item::viewItem()
{
    cout<<"\t\t\tName     : "<<item_name<<endl;
    cout<<"\t\t\t\tIngredients   "<<endl;
    cout<<"\t\t\t---------------------------------- "<<endl;
    for(auto& itr: it)
    {
        itr.display();
        cout<<endl;
    }
    cout<<endl;
    cout<<"\t\t\tTime : "<<time<<" mins"<<endl;
    cout<<"\t\t\tTime : "<<temp<<" *C"<<endl;
    cout<<"\t\t\tCalorie  : "<<(item_calorie/1000)<<" Kcal"<<endl;
    cout<<"\t\t\tPrice    : "<<"Rs "<<cost<<"/- "<<endl<<endl;
}

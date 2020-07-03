#include "ingredient.h"

 #include <string>
 #include <vector>
 #include <iostream>
 #include <stdlib.h>
 #include <bits/stdc++.h>
 #include <fstream>
 #include <sstream>
 #include <cstdlib>

 using namespace std;

Ingredient::Ingredient()
{

}

            Ingredient::Ingredient(string str,vector <string>& details,Ingredient& in)
        {
            size_t pos1 = 0,pos2=0;
            str=str+";";
            string token1,token2,delimiter1=";",delimiter2=",";
            while ((pos1 = str.find(delimiter1)) != string::npos)
                {
                    token1 = str.substr(0, pos1);
                    details.push_back(token1);
                    str.erase(0, pos1 + delimiter1.length());

                }
                string shape=details[1];
                shape=shape+",";
                while ((pos2 = shape.find(delimiter2)) != string::npos)
                {
                    string tkn;
                    tkn = shape.substr(0, pos2);
                    shapes.push_back(tkn);
                    shape.erase(0, pos2 + delimiter2.length());
                }
                in.setName(details[0]);
                in.setShapes(shapes);
                shapes.clear();
                in.setQuantity(atof(details[2].c_str()));
                in.setCalorie(atof(details[3].c_str()));
                in.setPrice(atof(details[4].c_str()));
                details.clear();

        }
        void Ingredient::display()
        {
            cout<<"\t\t\tName     : "<<name<<endl;
            cout<<"\t\t\tShapes   : ";
            for(auto& itr: shapes)
            {
                cout<<itr<<" ";
            }
            cout<<endl;
            cout<<"\t\t\tQuantity : "<<quantity<<endl;
            cout<<"\t\t\tCalorie  : "<<calorie<<endl;
            cout<<"\t\t\tPrice    : "<<price<<endl<<endl;
        }


        void Ingredient::setName(string c_name)
        {
                name=c_name;
        }
        void Ingredient::setShapes(vector<string> c_shapes)
        {
                shapes=c_shapes;
        }
        void Ingredient::setQuantity(double c_quantity)
        {
                quantity=c_quantity;
        }
        void Ingredient::setCalorie(double c_calorie)
        {
                calorie=c_calorie;
        }
        void Ingredient::setPrice(double c_price)
        {
                price=c_price;
        }
        string Ingredient:: getName()
        {
                return name;
        }
        vector <string> Ingredient:: getShapes()
        {
                return shapes;
        }
        double Ingredient:: getQuantity()
        {
                return quantity;
        }
        double  Ingredient::getCalorie()
        {
                return calorie;
        }
        double Ingredient:: getPrice()
        {
                return price;
        }
        void Ingredient::write_file(Ingredient& obj,string path)
        {
            fstream file;
            file.open(path,ios::app);
            if(!file)
            {
                cout<<"ille"<<endl;
            }
            file << obj.getName() << ";";
            vector<string> shapes;
            shapes=obj.getShapes();
		   	for(int i=0;i<shapes.size();i++)
		   		{
					if(i < shapes.size()-1)
					file<<shapes.at(i)<<",";
					else
					file<<shapes.at(i)<<";";
				}
		   	file << obj.getQuantity()<< ";"<< obj.getCalorie()<< ";"<< obj.getPrice() << ";"<<endl;
  			file.close();
  			shapes.clear();
        }


#include <iostream>
 #include <string>
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include "ingredient.h"
 #include "item.h"
 #include "ui.h"
 namespace{
 vector<Ingredient> ing_vec;
 string path="test.txt";
 vector<Item> it_vec;
 }
using namespace std;
Ingredient ing;
Item it;
int main()
{

    vector<string> vec;
    UI ui;
    Ingredient in;

    string str;
    fstream fs;
    fs.open(path,ios::in);
    while(getline(fs,str))
    {
    Ingredient(str,vec,in);
    ing_vec.push_back(in);
    }
    fs.close();
    while(1)
    {
     cout<<"\n\t\t\t\t--------------------------------"<<endl;
	 cout<<"\t\t\t\t|           BAKE ME            |"<<endl;
	 cout<<"\t\t\t\t--------------------------------"<<endl;
     cout<<"\n\n\t\t\t =================================================================\n";
 	 cout<<"\t\t\t  1 . Add Ingredients   \t  5 . Create Baking Item"<<endl;
 	 cout<<"\t\t\t  2 . View Ingredients  \t  6 . View Baking Items"<<endl;
	 cout<<"\t\t\t  3 . Update Ingredient \t  7 . Bake an Item "<<endl;
	 cout<<"\t\t\t  4 . Delete Ingredient \t  8 . Estimate Inventory Production"<<endl;
	 cout<<"\t\t\t\t\t\t  9 . EXIT"<<endl;
	 cout<<"\t\t\t =================================================================\n";
	 cout<<"\t\t\t  Enter a choice: ";
	 char ch;
	 cin>>ch;
        if(ch>57 || ch<48)
        {
        	cout<<"\t\t\tPlease enter a valid choice. : ";
        	continue;
        }
        cout<<endl<<endl;
        switch(ch)
		{
			case '1':
				{

                    in=ui.addIngredient();
                    ing_vec.push_back(in);
                    in.write_file(in,path);
				}

				break;
			case '2':
				{
                  for(auto& itr: ing_vec)
                        {
                        itr.display();
                        }

				}
//
				break;
			case '3':
				{
                    ui.updateIngredient(ing_vec);
                }
				break;
			case '4':
				{
                    ui.deleteIngredient(ing_vec);
                }
				break;
			case '5':
				{
                    it=ui.addItem(ing_vec);
                    it_vec.push_back(it);
				}
				break;
			case '6':
				{
                    for(auto& itr: it_vec)
                        {
                        itr.viewItem();
                        }
				}
				break;
			case '7':
				{

				}
				break;
			case '8':
				{


				}
				break;
			case '9':
			return 0;
				break;
			default:
				cout<<"\t\t\tEnter proper choice from 1-5:"<<endl;
				break;
		}

}
return 0;
}





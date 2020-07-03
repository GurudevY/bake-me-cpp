#ifndef UI_H
#define UI_H
#include "ingredient.h"
#include "item.h"
 #include <string>
 #include <vector>
 #include <iostream>
 #include <fstream>
 #include <cstdlib>


class UI
{
    public:
       Ingredient addIngredient();
       void updateIngredient(vector<Ingredient>& ing_vec);
       void updateQuantity(vector<Ingredient>& ing_vec);
       void updateShapes(vector<Ingredient>& ing_vec);
       void updateCalorie(vector<Ingredient>& ing_vec);
       void updatePrice(vector<Ingredient>& ing_vec);
       void deleteIngredient(vector<Ingredient>& ing_vec);

       Item addItem(vector<Ingredient>& ing_vec);
       void updateItem(vector<Ingredient>& ing_vec);
       void updateIngredientsList(vector<Ingredient>& ing_vec);
       void updateQuantityContents(vector<Ingredient>& ing_vec);
       void deleteItem(vector<Ingredient>& ing_vec);

    protected:

    private:
};

#endif // UI_H

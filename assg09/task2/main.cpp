#include "fractionType.h"

//use the ingredients to make the first dish
void MakeFirstDish(fractionType &tomato, fractionType &garlic, fractionType &onion, fractionType &butterBar, fractionType &groundBeef, fractionType &bean)
{
    tomato=tomato-fractionType(1,2);
    garlic=garlic-fractionType(3,4);
    onion=onion-fractionType(1,4);
    butterBar=butterBar-fractionType(1,8);
    groundBeef=groundBeef-fractionType(1,2);
    bean=bean-fractionType(2,3);
}

//use the ingredients to make the second dish
void MakeSecondDish(fractionType &tomato, fractionType &garlic, fractionType &onion, fractionType &butterBar, fractionType &groundBeef, fractionType &bean)
{
    tomato=tomato-fractionType(3,5);
    garlic=garlic-fractionType(1,5);
    onion=onion-fractionType(2,5);
    butterBar=butterBar-fractionType(1,5);
    groundBeef=groundBeef-fractionType(7,10);
    bean=bean-fractionType(9,10);
}

int main()
{
    fractionType tomato(3,1), garlic(1,1), onion(2,1), butterBar(1,1), groundBeef(2,1), bean(2,1);
    //use the ingredients to make the first dish
    MakeFirstDish(tomato,garlic,onion,butterBar,groundBeef,bean);
    //use the ingredients to make the second dish
    MakeSecondDish(tomato,garlic,onion,butterBar,groundBeef,bean);
    cout<<"Ingredients left:"<<endl;
    cout<<"Tomato: "<<tomato<<endl;
    cout<<"Garlic: "<<garlic<<endl;
    cout<<"Onion: "<<onion<<endl;
    cout<<"ButterBar: "<<butterBar<<endl;
    cout<<"GroundBeef: "<<groundBeef<<endl;
    cout<<"Bean: "<<bean<<endl;
    //compare the total weigh of the 2 dishes and output the result
    if ((fractionType(1,2)+fractionType(3,4)+fractionType(1,4)+fractionType(1,8)+fractionType(1,2)+fractionType(2,3))>
        (fractionType(3,5)+fractionType(1,5)+fractionType(2,5)+fractionType(1,5)+fractionType(7,10)+fractionType(9,10)))
    {
        cout<<"The first dish weighs more."<<endl;
    }
    else if ((fractionType(1,2)+fractionType(3,4)+fractionType(1,4)+fractionType(1,8)+fractionType(1,2)+fractionType(2,3))<
            (fractionType(3,5)+fractionType(1,5)+fractionType(2,5)+fractionType(1,5)+fractionType(7,10)+fractionType(9,10)))
    {
        cout<<"The second dish weighs more."<<endl;
    }
    else
    {
        cout<<"The two dishes weigh the same."<<endl;
    }
    return 0;
}

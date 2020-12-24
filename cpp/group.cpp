#include "group.h"

Group::Group(string nom):name(nom){list();}

string Group::getname(){
    return name;
}

void Group::display(){
    cout<<"group name: "+name<<endl;
    cout<<"The content: "<<endl;
    for(auto it = this->begin();it != this->end(); ++it){
        (*it)->display();
    }
}

string Group::retattr(){
    string out = "group name: " + name +"\n";
    for(auto it = this->begin();it != this->end(); ++it){
      out = out +"\n" +(*it)->name;
    }
    return out;
}

#include "admi.h"

myptr Admi::create_photo(string name, string filename,double longitu,double latitu){
    myptr pptr (new Photo(name,filename,longitu,latitu));
    media_table[name] = pptr;
    return pptr;
}

myptr Admi::create_video(string name, string filename,int dur){
    myptr vptr(new Video(name,filename,dur));
    media_table[name] = vptr;
    return vptr;

}

myptr Admi::create_film(string name, string filename, unsigned int num, int* dur){
    myptr fptr(new Film(name,filename,num,dur));
    media_table[name] = fptr;
    return fptr;
}

myptr_g Admi::create_group(string group_name){
    myptr_g gptr(new Group(group_name));
    group_table[group_name] = gptr;
    return gptr;
}

void Admi::display(string name){
    auto it_m = media_table.find(name);
    auto it_g = group_table.find(name);
    if(it_m!=media_table.end()){
        media_table.at(name)->display();
    }
    else if (it_g!=group_table.end()) {
        group_table.at(name)->display();
    }
    else cout<<"There is no such key"<<endl;
}

void Admi::play(string name){
    auto it_m = media_table.find(name);
    if(it_m!=media_table.end()){
        media_table.at(name)->play();
    }

    else cout<<"There is no such key"<<endl;
}

void Admi::del(string name){
    auto it_m = media_table.find(name);
    auto it_g = group_table.find(name);
    if(it_m!=media_table.end()){
        for(auto it = group_table.begin();it!=group_table.end();it++){
            myptr_g gptr = it->second;
            gptr->remove(it_m->second);

        }
        media_table.erase(it_m);
    }
    else if (it_g!=group_table.end()) {
        group_table.erase(it_g);
    }
}

string Admi::retattr(string name){
    auto it_m = media_table.find(name);
    auto it_g = group_table.find(name);
    if(it_m!=media_table.end()){
       return media_table.at(name)->retattr();
    }
    else if (it_g!=group_table.end()) {
        return group_table.at(name)->retattr();
    }
    else
        return "There is no such key";
}

#include "photo.h"

Photo::Photo(){
    longitude = 0;
    latitude = 0;
}

Photo::Photo(string in_name,string in_filename,double longitu,double latitu):Multimedia(in_name,in_filename){
    longitude = longitu;
    latitude = latitu;
}

Photo::~Photo(){cout<<"====================="<<endl<<"Photo is destructed"<<endl;}

double Photo::getlatitude(){
    return latitude;
}

double Photo::getlongitude(){
    return longitude;
}

void Photo::setlatitude(double in_latitude){
    latitude = in_latitude;
}

void Photo::setlongitude(double in_longitude){
    longitude = in_longitude;
}

void Photo::play(){
    string play = "eog " + getfilename();
    system(play.c_str());
}

void Photo::display(){
    cout<<"photo :" + this->getname()<<"  "<<"longitude: "<<longitude<<" "<<"latitude: "<<latitude<<endl;
}

string Photo::retattr(){
    string l = to_string(this->longitude);
    string la = to_string(this->latitude);
    return "photo : " + this->getname()+ "  " + "longitude: " + l +"  "+"latitude: " + la;
}

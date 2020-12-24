#include "video.h"
Video::Video() { duration = 0; }

Video::Video(string in_name, string in_filename,int dur) : Multimedia(in_name,in_filename){
    duration = dur;
}

Video::~Video(){cout<<"====================="<<endl<<"Viedo is destructed"<<endl;}

int Video::getduration() {
    return duration;
}

void Video::setduration(int in_duration) {
    duration = in_duration;
}

void Video::play() {
    string play = "mpv " + getfilename() + "&";
    system(play.c_str());
}

void Video::display(){
    cout<<"video :" +this->getname()<<"  "<<"duration is :"<<duration<<endl;
}

string Video::retattr(){
    string d = to_string(this->duration);
    return  "video :" +this->getname()+"  "+ "duration is :"+d;
}

#include "film.h"

Film::Film(){
    num_chapter = 0;
    _durations = nullptr;
}

Film::Film(string in_name,string in_filename,unsigned int num, int* _duration){
    this->name = in_name;
    this->filename = in_filename;
    this->passduration(num,_duration);
}

void Film::passduration(unsigned int num ,int* _duration){
    this->num_chapter = num;
    this->_durations =  new int [num];
    for(unsigned int i = 0;i<num;i++){
        _durations[i] = _duration[i];
    }
}

unsigned int Film::getnchapter(){
    return num_chapter;
}

int* Film::getduration(){
    int * const_dur = new int [num_chapter];
    for(unsigned int i = 0;i < num_chapter; i ++){    // copy the table, and return a new table so that users can't change the real table
        const_dur[i] = _durations[i];
    }
    return const_dur;
}

Film::~Film(){
    if(_durations){
        delete []_durations;
    }
    cout<<"====================="<<endl;
    cout<<"Film is destructed"<<endl;
}

void Film::display(){
    for (unsigned i = 0;i<num_chapter;i++){
        cout<<"The duration of part "<<i<<" is: "<<_durations[i]<<" mins"<<endl;
    }
}

Film::Film(const Film& from):Video(from){
    num_chapter = from.num_chapter;
    if(from._durations) {
        _durations = new int [num_chapter];
        for(unsigned int i = 0;i<num_chapter;i++){
            _durations[i] = from._durations[i];
        }
    }
    else {
        _durations = nullptr;
    }
}

Film& Film::operator=(const Film& from){
    Video::operator=(from);
    num_chapter = from.num_chapter;
    if(_durations&&from._durations){
        for(unsigned int i = 0;i<num_chapter;i++){
            _durations[i] = from._durations[i];
        }
    }
    else {
        delete _durations;
        if(from._durations) {
            _durations = new int [num_chapter];
            for(unsigned int i = 0;i<num_chapter;i++){
                _durations[i] = from._durations[i];
            }
        }
        else {
            _durations = nullptr;
        }
    }
    return *this;
}

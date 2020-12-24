#include "multimedia.h"

Multimedia::Multimedia(){
    name = "unknown";
    filename = "unknown";
}

Multimedia::Multimedia(string in_name,string in_filename):name(in_name),filename(in_filename){}

Multimedia::~Multimedia(){}

const string Multimedia::getname() { return name; }

const string Multimedia::getfilename() { return filename; }

void Multimedia::setname(string in_name) {
    name = in_name;
}

void Multimedia::setfilename(string in_name) {
    filename = in_name;
}


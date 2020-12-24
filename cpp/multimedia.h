#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include<string>
#include<iostream>
using namespace std;

class Multimedia
{
protected:
    /**
     * @brief name - name of the multidedia
     * @brief filename- the store path of the multimedia
     */
    string name;
    string filename;  
public:
    Multimedia();

    /**
     * @brief Multimedia -useful constructor
     * @param in_name    -name of file
     * @param in_filename - path of file
     */
    Multimedia(string in_name, string in_filename);

    /**
     * @brief ~Multimedia - destructor
     */
    virtual ~Multimedia();

    /**
     * @brief getname -obtain the name of the file
     * @return - the name of the file
     */
    const string getname();

    /**
     * @brief getfilename -obtain the path of file
     * @return - the path of the file
     */
    const string getfilename();

    /**
     * @brief setname - set the name of the file
     * @param in_name - the new name of the file
     */
    void setname(string in_name);

    /**
     * @brief setfilename - set the path of file
     * @param in_name- the path of file
     */
    void setfilename(string in_name);

    /**
     * @brief display - display the attribute of the multimedia
     */
    virtual void display()=0;

    /**
     * @brief play - play the multimedia
     */
    virtual void play()=0;

    /**
     * @brief retattr - return the attribute of the media
     * @return - return the attribute that will convert to "client"
     */
    virtual string retattr()=0;

    friend class Group;

};


#endif // MULTIMEDIA_H

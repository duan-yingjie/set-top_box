#ifndef ADMI_H
#define ADMI_H
#include"photo.h"
#include"group.h"
#include"film.h"
#include<map>

/**
 * @brief myptr - use smart pointer to manage
 */
typedef std::shared_ptr<Multimedia> myptr;
typedef std::shared_ptr<Group> myptr_g;
class Admi
{
    /**
     * @brief media_table- table of multimedia
     * @brief group-talbe- table of group
     */
    map<string,myptr> media_table;
    map<string,myptr_g> group_table;
public:
    /**
     * @brief create_photo- create a photo
     * @return - return the pointer of the object that we create
     */
    myptr create_photo(string name,string filename,double longitu,double latitu);

    /**
     * @brief create_video- create the video
     */
    myptr create_video(string name, string filename,int dur);

    /**
     * @brief create_film- create the film
     */
    myptr create_film(string name, string filename,unsigned int num,int* dur);

    /**
     * @brief create_group- create the group
     */
    myptr_g create_group(string group_name);

    /**
     * @brief display - displayt the attribute of the object that we choose
     * @param name - the name of the object
     */
    void display(string name);

    /**
     * @brief play - play the object that we choose
     * @param name - the name of the multimedia
     */
    void play(string name);

    /**
     * @brief del - delete the group or multimedia
     * @param name - the name of the multimedia
     */
    void del(string name);

    string retattr(string name);
};


#endif // ADMI_H

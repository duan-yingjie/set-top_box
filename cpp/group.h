#ifndef GROUP_H
#define GROUP_H
#include <list>
#include "multimedia.h"
#include<memory>
/**
 * @brief myptr-smart pointer to create a multimedia table
 */
typedef std::shared_ptr<Multimedia> myptr;


class Group : public list<myptr>
{
private:
    /**
     * @brief name- The name of the group
     */
    string name;
public:
    /**
     * @brief getname - Obtain the name of the group
     * @return - The name of the group
     */
    string getname();

    /**
     * @brief display- Display the attribute of the member of the group
     */
    void display();

    string retattr();

protected:
     Group(string nom);

     friend class Admi;
};

#endif // GROUP_H

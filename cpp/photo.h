#ifndef PHOTO_H
#define PHOTO_H

#include"multimedia.h"

class Photo:public Multimedia
{
    /**
     * @brief latitude-latitude of photo
     * @brief longitude-longitude of photo
     */
    double latitude;
    double longitude;
public:


    ~Photo() override;

    /**
     * @brief getlatitude-get the latitude of photo
     * @return -latitiude of photo
     */
    double getlatitude();

    /**
     * @brief getlongitude-get longitude of photo
     * @return -longitude of photo
     */
    double getlongitude();

    /**
     * @brief setlatitude-set the latitude of photo
     * @param in_latitude-the new latitude
     */
    void setlatitude(double in_latitude);

    /**
     * @brief setlongitude-set the longitude of photo
     * @param in_longitude- the new longitude
     */
    void setlongitude(double in_longitude);

    /**
     * @brief play-play the photo
     */
    void play() override;

    /**
     * @brief display- display the attribute of the photo
     */
    void display() override;

    /**
     * @brief retattr- return the attribute of the photo
     * @return - attribute of the photo
     */
    string retattr() override;
protected:
    Photo();

    /**
     * @brief Photo-constructor of photo.
     * put in the protected so wo just can use admi to create it,can't new it.
     */
    Photo(string in_name,string in_filename,double longitu,double latitu);

    friend class Admi;

};

#endif // PHOTO_H

#ifndef VIDEO_H
#define VIDEO_H

#include"multimedia.h"


class Video:public Multimedia
{
    /**
     * @brief duration-the duration of the video
     */
    int duration;
public:

    ~Video() override;

    /**
     * @brief getduration-get the duration
     * @return -the duration of video
     */
    int getduration();

    /**
     * @brief setduration-set the duration
     * @param in_duration-new duration
     */

    void setduration(int in_duration);

    /**
     * @brief display-display the attribute of video
     */
    void display() override;

    void play() override;

    string retattr() override;
protected:
    Video();

    /**
     * @brief Video - constructor of video
     * @param in_name- name of the video
     * @param in_filename-path of the video
     * @param dur- duration of the video
     */
    Video(string in_name, string in_filename,int dur);

    /**
     *so we just can use Admi to new it.
     */
    friend class Admi;

};


#endif // VIDEO_H

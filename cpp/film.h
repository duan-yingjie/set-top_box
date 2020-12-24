#ifndef MOVIE_H
#define MOVIE_H
#include"video.h"

class Film : public Video
{
 /**
 * @brief num_chapter- The number of chapter
 * @brief _durations -  A table of duration of each chapter
 */
unsigned int num_chapter;
int* _durations;

public:
    /**
     * @brief passduration - get the duration from outside
     * @param num- number of chapter
     * @param _duration - table of duration
     */
    void passduration(unsigned int num ,int* _duration);

    /**
     * @brief getnchapter- get the number of duration
     * @return -the number
     */
    unsigned int getnchapter();

    /**
     * @brief getduration- get the duration table
     * @return -duration table
     */
    int* getduration();

    ~Film();

    void display ();

    /**
     * @brief Film-copy constructor
     * @param from- source of copy
     */
    Film(const Film&from);

    /**
     * @brief operator = - overload the operator =
     * @param from-copy source
     * @return - copy of the film class
     */
    Film& operator = (const Film& from);

protected:
    Film();

    Film(string in_name,string in_filename,unsigned int num, int* _duration);

    friend class Admi;



};

#endif // MOVIE_H

#include <iostream>
#include "video.h"
#include "photo.h"
#include"film.h"
#include"group.h"
#include"admi.h"
#include<memory>
/**
 * @brief myptr-smart pointer of base class multimedia
 */
typedef std::shared_ptr<Multimedia> myptr;


using namespace std;

/**
 * @brief displaymedia - display a table of multimedia
 * @param mp - the pointer of the multimedia table
 * @param lenth- the lenth of the table
 */
void displaymedia(Multimedia** mp,int lenth){
    for(int i=0;i<lenth;i++){
        mp[i]->display();
    }
}

/**
 * @brief play- play a table of multimedia
 */
void play(Multimedia** mp, int lenth){
    for(int i=0;i<lenth;i++){
        mp[i]->play();
    }
}

/**
 * @brief question5 implement function of question 5
 */
void question5(Multimedia** pmedia,int lenth){
    displaymedia(pmedia,lenth);       // Print the attribute
    play(pmedia,lenth);               // Try play an array of viedos and photos

}


int main(int argc, const char* argv[]){
    Admi admi;
    int lenth = 4;
    Multimedia** pmedia = new Multimedia*[lenth];
    string photoname = "beauty.jpg";
    string photopath = "/home/duan/source/beauty.jpg";
    string videoname = "test.mp4";
    string videopath = "/home/duan/source/test.mp4";
    myptr pp = (admi.create_photo(photoname,photopath,10,10));
    myptr pv = (admi.create_video(videoname,videopath, 5));
    pmedia[0] = pp.get();
    pmedia[1] = pv.get();
    pmedia[2] = pp.get();
    pmedia[3] = pv.get();

    /* test question 5
    question5(pmedia,lenth);
    */

    int my_dur[] = {10,20,10,20};
    unsigned int num = sizeof (my_dur)/sizeof (my_dur[0]);
    myptr my_film = admi.create_film("film1.mp4","/home/duan/source/test.mp4",num,my_dur);
    /* test question 6
    Film* myf = (Film*) my_film.get();
    unsigned int num_chap = myf->getnchapter();
    int * get_dur = myf->getduration();
    cout<<"The number of chapter is: "<<num_chap<<endl;
    get_dur[0]=100;
    get_dur[1]=200;                     // Try to change the table we get and see if the real table is changed.
    my_film->display();                  // Print the real table to see if it's changed.
    for(int i = 0;i<num;i++){           // Print the table we get.
    cout<<"The table we change is: "<<get_dur[i]<<endl;}
    */



    /*Test question 7. We copy the film and delete the previous film to make sure we are profound copy
    int my_dur2[] = {30,40,30,40,30};
    unsigned int num2 = sizeof (my_dur2)/sizeof (my_dur2[0]);
    Film* my_film2 = new Film("film2.mp4","/home/duan/source/test.mp4",num2,my_dur2);
    cout<<"Use copy constructor to construct my_film3"<<endl;
    Film my_film3(*my_film);
    cout<<"delete my_film2"<<endl;
    delete my_film2;
    my_film3.display();
    cout<<"The number of chapter is: "<<my_film3.getnchapter()<<endl;
    Film my_film4;
    cout<<"Use operator = to construct my_film4"<<endl;
    my_film4 = *my_film;
    my_film4.display();
    cout<<"The number of chapter is: "<<my_film4.getnchapter()<<endl;
    */

    /*Test question 8. Create several groups to verify everythings are ok.
    Group* photo = new Group("group of photo");
    Group* video = new Group("group of video");
    Group* multimedia = new Group("group of multimedia");
    photo->push_back(pp);
    video->push_back(pv);
    multimedia->push_back(pp);
    multimedia->push_back(pv);
    cout<<"Display group photo"<<endl<<endl;
    photo->display();
    cout<<"Display group of video"<<endl<<endl;
    video->display();
    cout<<"Delete group photo and group video,then display multimedia"<<endl<<endl;
    delete photo;
    delete video;
    multimedia->display();
    */

    /* Test question 9
    Group* photo = new Group("group of photo");
    Group* video = new Group("group of video");
    Group* multimedia = new Group("group of multimedia");
    cout<<"Set photo and video to three group"<<endl;
    photo->push_back(pp);
    video->push_back(pv);
    multimedia->push_back(pp);
    multimedia->push_back(pv);
    cout<<"delete the smart pointer"<<endl;
    pp.reset();
    pv.reset();
    cout<<"delete the group"<<endl;
    delete photo;
    delete video;
    delete multimedia;
    */

     /* //Test question10. We can put all the constructor to protected, and add admi as friend. so just the class can create.
    myptr_g gptr = admi.create_group("group of photo");
    admi.display("beauty.jpg");
    admi.play("beauty.jpg");
    // test remove
    gptr->push_back(pp);
    admi.display("group of photo");
    admi.del("beauty.jpg");
    cout<<"display after delete"<<endl;
    admi.display("beauty.jpg");
    admi.display("group of photo");
    cout<<"Program finish"<<endl;
    */
    delete [] pmedia;
    return 0;

}


   // For question 8, we should change class film, we should delete the duration array at the end. Because the copy is superficial,
   // so it's copied field by field, so the content of pointer is not copied. So we should change the copy constructor and the operator
   // =.

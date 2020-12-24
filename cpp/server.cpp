//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include"admi.h"
using namespace std;
using namespace cppu;

const int PORT = 3331;
/**
 * @brief topbox- The database I create
 */
Admi topbox;

class MyBase {
public:
  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */



    bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;
    // My instruction consist of two part:
    // part1: the action. For exemple, 1 means search and display it, 2 means play, 3 means delete
    string part1;
    string part2;
    stringstream r(request);
    r>>part1;
    r>>part2;
    if(part1=="1")
    {
         string attri = topbox.retattr(part2);
         response = attri;

    }
    if(part1=="2")
    {
      topbox.play(part2);
      response = "play";
    }
    if(part1=="3"){
        topbox.del(part2);
        response = "delete "+part2;
    }
    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    
    
    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);


    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client

    
    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
};


int main(int argc, char* argv[])
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());

  // create the database
  myptr pp = topbox.create_photo("beauty","./source/beauty.jpg",20,20);
  myptr pv = topbox.create_video("coffee","./source/coffee.mp4",20);
  myptr pp1 = topbox.create_photo("shark","./source/shark.jpg",10,10);
  myptr pv1 = topbox.create_video("tea","./source/tea.mp4",10);


  // cree l'objet qui gère les données
  shared_ptr<MyBase> base(new MyBase());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyBase::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}


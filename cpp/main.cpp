//
//  main.cpp
//  

#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>

#include"base.h"
#include"photo.h"
#include"video.h"
#include"film.h"
#include"group.h"
#include"gestion.h"
#include"tcpserver.h"

//remember add gestion.h to makefile

using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {
    GestionPtr gestion;
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
  MyBase(GestionPtr gestion):gestion(gestion){}

  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;

    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    stringstream ss;
    ss.str(request);

    string type_req, cont_req;
    ss>>type_req>>cont_req;

    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);
    TCPLock lock(cnx);


    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    response = "Format : search/play filename";
    if(type_req == "search"){
        ostringstream os;
        BasePtr file = gestion->searchFile(cont_req);
        if (file->getObjetName() == ""){
            response = "This file doesn't exist";
        }
        else{
            file->display(os);
            response = os.str();
        }

    }
    else if(type_req == "play"){
        BasePtr file = gestion->searchFile(cont_req);
        if (file->getObjetName() == ""){
            response = "This file doesn't exist";
        }
        else{
            file->objetDisplay();
            response = "playing " + cont_req + " now";
        }

    }


    cerr << "response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
};

int main(int argc, char* argv[]) {

    //initiation des donnees
    GestionPtr ges = make_shared<Gestion>();

    GroupPtr group1 = ges->createGroup("group1");

    group1->push_back( make_shared<Video>("flower", "/cal/homes/szhang/inf224/drop.avi", 6));
    group1->push_back( make_shared<Photo>("drop", "/cal/homes/szhang/inf224/flower.jpeg", 2.1f, 3.2f));

    PhotoPtr p1 = ges->createPhoto("flower", "/cal/homes/szhang/inf224/flower.jpeg", 2.1f, 3.2f);
    VideoPtr v1 = ges->createVideo("drop", "/cal/homes/szhang/inf224/drop.avi", 6);

    //server

    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    shared_ptr<MyBase> base(new MyBase(ges));

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





    /* test

    cout << "hello world" << endl;

    GroupPtr g = make_shared<Group>("groupB");

    g->push_back( make_shared<Video>("ob200", "/cal/homes/szhang/inf224/drop.avi", 6));
    g->push_back( make_shared<Photo>("ob300", "/cal/homes/szhang/inf224/flower.jpeg", 2.1f, 3.2f));

    g->dispaly(cout);
    */


    /*
    Base * c1 = new Base("ob1", "file1");
    c1->display(cout);
    */

    /*
    Video * c2 = new Video("ob2", "/cal/homes/szhang/inf224/drop.avi", 5);

    Photo * c3 = new Photo("ob3", "/cal/homes/szhang/inf224/flower.jpeg", 1.1f, 2.2f);

    c2->display(cout);
    c3->display(cout);

    c2->objetDisplay();
    c3->objetDisplay();
    */

    /*
    Base ** table = new Base * [2];

    table[0] = new Video("ob200", "/cal/homes/szhang/inf224/drop.avi", 6);
    table[1] = new Photo("ob300", "/cal/homes/szhang/inf224/flower.jpeg", 2.1f, 3.2f);

    for (int i = 0; i <=1 ; i++){
        table[i]->display(cout);
        table[i]->objetDisplay();
    }
    */

    /*
    int * duration = new int [3];
    duration[0] = 20;
    duration[1] = 22;
    duration[2] = 23;

    int number = 3;

    Film * f1 = new Film("ob200", "/cal/homes/szhang/inf224/drop.avi", 6, duration, number);

    f1->displayDuree(cout);

    duration[2] = 24;
    f1->displayDuree(cout);

    delete [] duration;
    delete f1;
    */




}

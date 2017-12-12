//
//  main.cpp
//  

#include <iostream>
#include <string>

#include"base.h"
#include"photo.h"
#include"video.h"
#include"film.h"

using namespace std;

int main(int argc, char* argv[]) {

    /** test
     */
    cout << "hello world" << endl;

// 1/ Base * c1 = new Base("ob1", "file1");
// 1/ c1->display(cout);

// 2/   Video * c2 = new Video("ob2", "/cal/homes/szhang/inf224/drop.avi", 5);

// 2/   Photo * c3 = new Photo("ob3", "/cal/homes/szhang/inf224/flower.jpeg", 1.1f, 2.2f);

// 2/   c2->display(cout);
// 2/  c3->display(cout);

// 2/   c2->objetDisplay();
// 2/   c3->objetDisplay();


//    Base ** table = new Base * [2];

//    table[0] = new Video("ob200", "/cal/homes/szhang/inf224/drop.avi", 6);
//    table[1] = new Photo("ob300", "/cal/homes/szhang/inf224/flower.jpeg", 2.1f, 3.2f);

//    for (int i = 0; i <=1 ; i++){
//        table[i]->display(cout);
//        table[i]->objetDisplay();
//    }

    int * duration = new int [3];
    duration[0] = 20;
    duration[1] = 22;
    duration[2] = 23;

    int number = 3;

    Film * f1 = new Film("ob200", "/cal/homes/szhang/inf224/drop.avi", 6, duration, number);

    f1->displayDuree(cout);

    duration[2] = 24;
    f1->displayDuree(cout);

}

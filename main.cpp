#include "../CImgDir/CImg.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace cimg_library;
using namespace std;

#define math_pi 3.14159265

int main(void){
    auto spinning_barcode = CImg<unsigned char>("spinning_barcode.bmp");
    spinning_barcode.display();

    // considering 600*600 barcode pic
    // will be convert to 256*256 square barcode image

    CImg<unsigned char> square_barcode(256,256,1,3,0);

    // iteration on radius:44-300
    for(int radius=44;radius<300;radius++){
        // iteration on degree:0-360
        for(int degree=90;degree<450;degree++){
            // center position:299,299
            int currx=(double)299-((double)radius*sin(((double)degree/(double)180.0)*math_pi));
            int curry=(double)299-((double)radius*cos(((double)degree/(double)180.0)*math_pi));
            // convert to correct point
            int targetx=256*((double)(degree-90)/(double)360.0);
            int targety=256*((double)(radius-44)/(double)256.0);
            // set color
            cout << "Set color on" << currx << "," << curry << endl;
            for(int tunnel=0;tunnel<3;tunnel++){
                square_barcode(targetx,targety,0,tunnel)=spinning_barcode(currx,curry,0,tunnel);
            }
            cout << "Set color over r" << radius << "theta" << degree << endl;
        }
    }

    cout << "Set color process OVER." << endl;

    square_barcode.save_bmp("output.bmp");

    //square_barcode.display();
    

    return 0;
}
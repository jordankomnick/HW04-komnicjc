#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <iostream>
#include <fstream>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW04App::setup()
{
	string line;
	ifstream myfile;
	myfile.open("../include/Starbucks_2006.csv");
	if (myfile.is_open())
  {
    /*while ( myfile.good() )
    {*/
      getline (myfile,line);
      cout << line << endl;
    /*}*/
    myfile.close();
  }

  else cout << "Unable to open file";
}

void HW04App::mouseDown( MouseEvent event )
{
}

void HW04App::update()
{
}

void HW04App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04App, RendererGl )

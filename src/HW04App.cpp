//some file i/o referenced from http://www.cplusplus.com/doc/tutorial/files/ and https://github.com/Sonodabe/HW04_Sonodabe

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "komnicjcStarbucks.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	Entry* locations;
	int count;
	komnicjcStarbucks* test;
};

void HW04App::setup()
{
	count = 0;
	string line;
	double num;
	ifstream myfile;
	myfile.open("../include/Starbucks_2006.csv");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
		  getline (myfile, line, ',');
		  getline (myfile, line, ',');
		  count++;
		}
		myfile.close();
	}
  else cout << "Unable to open file";

  locations = new Entry[count];

  int position = 0;
  myfile.open("../include/Starbucks_2006.csv");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
		  getline (myfile, line, ',');
		  (locations+position) -> identifier = line;
		  myfile >> (locations+position) -> x;
		  myfile.get();
		  myfile >> (locations+position) -> y;
		  myfile.get();
		  position++;
		}
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

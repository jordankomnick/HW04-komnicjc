//some file i/o referenced from http://www.cplusplus.com/doc/tutorial/files/ and https://github.com/Sonodabe/HW04_Sonodabe

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Starbucks.h"
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
};

void HW04App::setup()
{
	int count = 0;
	string line;
	double num;
	ifstream myfile;
	myfile.open("../include/Starbucks_2006.csv");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
		  getline (myfile, line);
		  count++;
		}
		myfile.close();
	}
  else cout << "Unable to open file";

  locations = new Entry[count];

  myfile.open("../include/Starbucks_2006.csv");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
			Entry* temp_entry = new Entry();
		  getline (myfile, line, ',');
		  temp_entry -> identifier = line;
		  myfile >> temp_entry -> x;
		  myfile.get();
		  myfile >> temp_entry -> y;
		  myfile.get();
		  count++;
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

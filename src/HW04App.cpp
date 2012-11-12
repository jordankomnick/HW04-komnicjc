//some file i/o referenced from http://www.cplusplus.com/doc/tutorial/files/ and https://github.com/Sonodabe/HW04_Sonodabe

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "komnicjcStarbucks.h"
#include <iostream>
#include <fstream>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	void setup();
	void plotPoints(uint8_t* pixels, Entry* locations, int count);
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	Entry* locations;
	int count;
	static const int kAppWidth = 800;
	static const int kAppHeight = 600;
	static const int kTextureSize = 1024;
	komnicjcStarbucks* test;

	private:
	Surface* mySurface_;
	uint8_t* dataArray;
};

void HW04App::setup()
{
	mySurface_ = new Surface(kTextureSize,kTextureSize,false);
	count = 0;
	string line;
	double num;
	ifstream myfile;
	myfile.open("../include/starbuckstest.csv");
	if (myfile.is_open())
	{
		while ( myfile.good() )
		{
		  getline (myfile, line, ',');
		  getline (myfile, line, ',');
		  count++;
		}
	}
  else cout << "Unable to open file";

  locations = new Entry[count];

  myfile.clear();
  myfile.seekg(0);

  int position = 0;
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

	test = new komnicjcStarbucks;
	test -> build(locations, count);
	Entry* result = test -> getNearest(rand(), rand());
	cout << result;
	
}

void HW04App::plotPoints(uint8_t* pixels, Entry* locations, int count)
{
	Color8u color = Color8u(0,255,0);
	for(int i = 0; i < count; i++)
	{
		int x = (locations+i) -> x * kAppWidth;
		int y = (locations+i) -> y * kAppHeight;
		for(int j = 0; j <= kAppWidth; j++)
		{
			for(int k = 0; k <= kAppHeight; k++)
			{
				int offset = 3*(j + k*kTextureSize);
				if(j == x && k == y)
				{
					pixels[offset] = pixels[offset]/2 + color.r/2;
					pixels[offset+1] = pixels[offset+1]/2 + color.g/2;
					pixels[offset+2] = pixels[offset+2]/2 + color.b/2;
				}
			}
		}
	}
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
	plotPoints(dataArray, locations, count);
}

CINDER_APP_BASIC( HW04App, RendererGl )

#include <iostream>
#include <math.h> // calculation needed library
#include <ctime>   // necessary for random generate number
#include <cstdlib> // necessary for random generate number
using namespace std;
const double pi=3.14; // constant number which is need to calculation

class Tracking{	// class which is taking position x and y , taking as a constructor first
	private:		
		double positionX;
		double positionY;		
	public:	 
	 Tracking (double _positionX,double _positionY)
	 {
	 	positionX=_positionX;
	 	positionY=_positionY;
	 }	 
	 double getPOSX(){ return positionX;}
	 double getPOSY(){ return positionY;}
	 	
};
class Camera{  // class which is taking from the user x , y , angle and distance . also has some functions.
		private:		
		double onX;
		double onY;
		double angle;
		double distance;
        bool isItInTheViewingDistance(double x,double y);
	    bool  isItInTheViewingAngle(double x,double y);
	    public:
		Camera(double x, double y, double ang, double dis) : onX(x) , onY(y) , angle(ang) , distance(dis){	}
		void viewFieldControl(double x,double y);		
};
bool Camera::isItInTheViewingDistance(double x,double y) // functýon which is return false or true and calculatýon of dýstance 
{
	onX=0;
	onY=0;
    double distance_calculated;
    bool a;  
     distance_calculated=sqrt((y*y)+(x*x));   
    if(distance<distance_calculated)
    {
    	a=false;
    	return (a);
	}
	else
	{
		a=true;        
		return a;
	}	
}                  
bool Camera::isItInTheViewingAngle(double x,double y) // function which is measure angle and calculatýon of angle and compare ,
                                                      // also return true or false
{
	double angle_calculated;
	bool b;	
	angle_calculated=(acos(((onX*x)+(onY*y))/(sqrt((onX*onX)+(onY*onY))*sqrt((x*x)+(y*y))))*180) / pi;	
	if(angle_calculated>(angle/2))
	{
		b=false;
		return b;
	}	
	else
	{
		b=true;
		return b;
	}	
}
void Camera::viewFieldControl(double x,double y)  // functýon which is taking value from others functýon true or false , 
                                                  //compare is it same then makýng decýsýon about fýeld or not
{
	bool a;
	bool b;
	 a=isItInTheViewingDistance(x,y);
	 b=isItInTheViewingAngle(x,y);	 
	 if(a && b )	 
	cout<<"Object is in field of view at "<<"("<<x <<","<<y<<")";  
	else	
	cout<<"Object is not in field of view";	
}
int main()
{
    srand (time(NULL)); // its needed for generated dýfferent numbers
	int randomNumX = rand() % 201 + (-100); // generatýng dýfferent numbers -100 between 100
	int randomNumY = rand() % 201 + (-100); // generatýng dýfferent numbers -100 between 100
	Tracking track(randomNumX,randomNumY); // create class object and sending parameters to constructor
	double onX,onY,distance,angle; // varýables
	cout<<"Enter the forward position of camera (x,y):"; // message for taking position x and y for camera class
	cin>>onX >>onY; // taking values to onx and ony
	cout<<"Enter the view distance:"; // message for takýng dýstance number
	cin>>distance; // takýng dýstance value 
	cout<<"Enter the view angle:"; // message for takýng angle number
	cin>>angle;	// taking dýstance value
	Camera cam(onX,onY,distance,angle); // create class object cam and sendýng parameters to constructor
	cam.viewFieldControl(randomNumX,randomNumY); // sendýng values to functýon whých ýs members of camera class
}




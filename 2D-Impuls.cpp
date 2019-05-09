#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// KLASS DEFINITION
	//vector definition
struct vekt {
	double x;
	double y;	
};
	//body definition
struct korp{
	double mas;
	double rad;
	vekt ort;
	vekt ges;
	vekt imp;
};

// FUNCTION DEFINITION AREA
	
	//KOSMETIK AREA
		//seperation line function
		int sep(){
			cout << "   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
		}
		//greetings-banner for use at the beguinning (sorry its in german)
		int greet(){
			sep();
			cout << "   X  _____        ______                 ______       _________   ______       ______       ______      X "<< endl;
			cout << "   X /_____/\\     /_____/\\               /_____/\\     /________/\\ /_____/\\     /_____/\\     /_____/\\     X " << endl;
			cout << "   X \\:::_:\\ \\    \\:::_ \\ \\     _______  \\::::_\\/_    \\__.::.__\\/ \\:::_ \\ \\    \\::::_\\/_    \\::::_\\/_    X " << endl;
			cout << "   X     _\\:\\|     \\:\\ \\ \\ \\   /______/\\  \\:\\/___/\\      \\::\\ \\    \\:\\ \\ \\ \\    \\:\\/___/\\    \\:\\/___/\\   X " << endl; 
			cout << "   X    /::_/__     \\:\\ \\ \\ \\  \\__::::\\/   \\_::._\\:\\      \\::\\ \\    \\:\\ \\ \\ \\    \\_::._\\:\\    \\_::._\\:\\  X " << endl;
			cout << "   X    \\:\\____/\\    \\:\\/.:| |               /____\\:\\      \\::\\ \\    \\:\\_\\ \\ \\     /____\\:\\     /____\\:\\ X " << endl;
			cout << "   X     \\_____\\/     \\____/_/               \\_____\\/       \\__\\/     \\_____\\/     \\_____\\/     \\_____\\/ X " << endl;
			cout << "   X                                                                                                     X " << endl;
	    	sep();
			cout << "   X                                 BY RAPHAELA, TOBIAS, MANUEL, LUKAS                                  X " << endl;
			sep();
			cout << endl;	
		}
	
	//THE REAL FUNCTION AREA
		//function for entering variables
		double eing(string var){
			double a;
			cout << "   Please enter " << var << " : ";
			cin >> a;
			return a;
		}
		//function to calculate the current position
		double pos( double ord, double ges, double t){	
		    ord = ord + (ges*t);
			return ord;
		}
		//function for the amont of a vector
		double betr(vekt v){
			return sqrt((pow(v.x,2)+pow(v.y,2)));
		}
		//function for the kollision detection
		bool koll( korp k1, korp k2){
			//Vector Ok1 - Ok2 = k
			vekt k;
			k.x = k1.ort.x - k2.ort.x;
			k.y = k1.ort.y - k2.ort.y;
			//calculating the amount of vector k
			double amk = betr(k);
			//checking if there is a kollision
			if (amk<=(k1.rad+k2.rad)){
				return true;
			}
			else{
				return false;
			}			
		}

//MAINROUTINE
int main(){
	
	//INITIALISATION 
		
		//initialising the CSV-File
		fstream f;
		f.open("2dSym.csv", ios::out);
		//first line of the CSV-File
		f<<"time; k1_x; k1_y; k2_x; k2_y;"<<endl;
		//initialising greeting
		greet();
		
		//defining Variables
			//definition of the area
			int l = 2; //length
			int b = 1; //width
			//defining a flag for the kollision
			bool flag = false;
			//defining an index for the main loop
			int index = 0;
		
	//IMPUT AREA
		//setting the time
		double dt = eing("the duration of the simulation in seconds");
		double t = eing("the time interval");
		//setting variables 
		
			//defining k1
				cout << endl << "   DEFINING THE BODY OF K1" << endl;
				korp k1;
				//imput the body forms
				k1.mas = eing("the mass of k1 in kg"); 			//mass of body k1
				k1.rad = eing("the radius of k1 in m");			//radius of body k1
				//setting the speed of k1
				k1.ges.x = eing("the speed of k1 in m/s");
				k1.ges.y = 0;
				//seperation between imputs
				cout << endl;
				sep();
				cout << endl;
								
			//defining k2
				cout << "   DEFINING THE BODY OF K2" << endl; 
				korp k2;
				//imput the body forms
				k2.mas = eing("the mass of k2 in kg");			//mass of body k2
				k2.rad = eing("the radius of k2 in m");			//radius of body k1
				//setting the speed of k2
				k2.ges.x = eing("the speed of k1 in m/s");
				k2.ges.y = 0;
				//seperation between imputs
				cout << endl;
				sep();
				cout << endl;
			
		//setting the hight difference
		double h = eing ("the hight difference between two bodies in m");
		sep();
		
		//TROUBLESHOOTING THE IMPUT
		while (true){
			if(h<=(k1.rad+k2.rad) && k2.ges.x < 0 && k1.ges.x > 0 && k1.mas > 0 && k2.mas >0  && k1.rad > 0 && k2.rad > 0 && t > 0 ){
				break;
			}
			else if(h>(k1.rad+k2.rad)){
				cout << "   The entered hight difference is invalid the value has to be lower than: " << k1.rad+k2.rad << endl;
				h = eing("the hight difference in m again");
				cout << endl;
			}
			else if (k2.ges.x > 0){
				cout << "   The entered speed of the body k2 has to be negativ" << endl;
				k2.ges.x = eing("the speed of body k1 in m/s again");
				cout << endl;
			}
			else if (k1.ges.x < 0){
				cout << "   The entered speed of the body k1 has to be positiv" << endl;
				k1.ges.x = eing("the speed of body k2 in m/s again");
				cout << endl;				
			}
			else if (k1.mas <= 0){
				cout << "   The entered mass of the body k1 has to be positiv" << endl;
				k1.mas = eing("the mass of body k1 in kg again");
				cout << endl;
			}
			else if (k2.mas <= 0){
				cout << "   The entered mass of the body k2 has to be positiv" << endl;
				k2.mas = eing("the mass of body k2 in kg again");
				cout << endl;
			}
			else if (k1.rad <= 0){
				cout << "   The entered radius of body k1 has to be bigger than zero" << endl;
				k1.rad = eing("the radius of body k1 in m again");
				cout << endl;
			}
			else if (k2.rad <= 0){
				cout << "   The entered radius of body k2 has to be bigger than zero" << endl;
				k2.rad = eing("the radius of body k2 in m again");
				cout << endl;
			}
			else {
				cout << "   The time intervall has to be bigger than zero" << endl;
				t = eing("the time interval in s again");
				cout << endl;
			}			
		}
	//CALCULATING location and impuls
		//setting the location of the bodies
		k1.ort.x = 0;
		k1.ort.y = (0.5*b);
		k2.ort.x = l;
		k2.ort.y = (0.5*b)-h;
		//calculating the impuls
		k1.imp.x = k1.ges.x * k1.mas;
		k1.imp.y = k1.ges.y * k1.mas;
		k2.imp.x = k2.ges.x * k2.mas;
		k2.imp.y = k2.ges.y * k2.mas;
		
	//MAIN LOOP
		while(index < dt){
			//counting up the index
			index = index + t;
			//kollision detection
			if (koll(k1,k2) == true && flag == false){
				//setting the kollision-flag true
				cout << "   kollision detectet after "<< index << " seconds"<< endl;
				flag = true;
				double sina = (h/(k1.rad+k2.rad));
				//splitting the vectors
				vekt p1a, p1b, p2a, p2b;
					//vector p1 = p1a + p1b				
					p1b.y = pow(sina,2) * betr(k1.imp);
					p1b.x = sqrt(pow(betr(k1.imp)*sina,2)-pow(p1b.y, 2));
					//vectro p2 = p2a + p2b
					p2b.y = -pow(sina,2) * betr(k2.imp);
					p2b.x = -sqrt(pow(betr(k2.imp)*sina,2)-pow(p2b.y, 2));
					//Vector p1-p1b = p1a
					p1a.x = k1.imp.x-p1b.x;
					p1a.y = k1.imp.y-p1b.y;
					//Vector p2-p2b = p2a	
					p2a.x = k2.imp.x-p2b.x;
					p2a.y = k2.imp.y-p2b.y;
					//constructing the resulting pa vektor
					vekt pa;
					pa.x = p1a.x + p2a.x;
					pa.y = p1a.y + p2a.y;
					//adding up the resulting vektor
					k1.imp.x = pa.x + p1b.x;
					k1.imp.y = pa.y + p1b.y;
					k2.imp.x = pa.x + p2b.x;
					k2.imp.y = pa.y + p2b.y;
					//changing the velocety
					k1.ges.x = (k1.imp.x/k1.mas);
					k1.ges.y = (k1.imp.y/k1.mas);
					k2.ges.x = (k2.imp.x/k2.mas);
					k2.ges.y = (k2.imp.y/k2.mas); 		
			}
			//cout << k1.ges.x << " "<< k1.ges.y << " "<< k2.ges.x << " "<< k2.ges.y << endl;
			//calculate new coordinates
			//k1 coordinates
			k1.ort.x = pos(k1.ort.x, k1.ges.x, t);
			k1.ort.y = pos(k1.ort.y, k1.ges.y, t);
			//k2 coordinates
			k2.ort.x = pos(k2.ort.x, k2.ges.x, t);
			k2.ort.y = pos(k2.ort.y, k2.ges.y, t);
			//Exit condition
			
			if (k1.ort.x > l || k2.ort.x < 0 || k1.ort.y > b || k1.ort.y < 0 || k2.ort.y >b || k2.ort.y <0 ){
				//exit message
				cout << "   One of the bodies hit the edge of the table after " << index << " seconds"<<endl;
				break;
			}
			else{
				//saving the Data in a csv-document
				f <<index<<"; "<< k1.ort.x <<"; "<< k1.ort.y << "; "<< k2.ort.x <<"; "<< k2.ort.y <<"; "<<endl;
			}
		}
}

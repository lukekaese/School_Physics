#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

#define PI 3.14159265

int greet(){
	cout << "   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
	cout << "   X  _____        ______                 ______       _________   ______       ______       ______      X "<< endl;
	cout << "   X /_____/\\     /_____/\\               /_____/\\     /________/\\ /_____/\\     /_____/\\     /_____/\\     X " << endl;
	cout << "   X \\:::_:\\ \\    \\:::_ \\ \\     _______  \\::::_\\/_    \\__.::.__\\/ \\:::_ \\ \\    \\::::_\\/_    \\::::_\\/_    X " << endl;
	cout << "   X     _\\:\\|     \\:\\ \\ \\ \\   /______/\\  \\:\\/___/\\      \\::\\ \\    \\:\\ \\ \\ \\    \\:\\/___/\\    \\:\\/___/\\   X " << endl; 
	cout << "   X    /::_/__     \\:\\ \\ \\ \\  \\__::::\\/   \\_::._\\:\\      \\::\\ \\    \\:\\ \\ \\ \\    \\_::._\\:\\    \\_::._\\:\\  X " << endl;
	cout << "   X    \\:\\____/\\    \\:\\/.:| |               /____\\:\\      \\::\\ \\    \\:\\_\\ \\ \\     /____\\:\\     /____\\:\\ X " << endl;
	cout << "   X     \\_____\\/     \\____/_/               \\_____\\/       \\__\\/     \\_____\\/     \\_____\\/     \\_____\\/ X " << endl;
	cout << "   X                                                                                                     X " << endl;
	cout << "   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl;
	cout << "   X                                 BY RAPHAELA, TOBIAS, MANUEL, LUKAS                                  X " << endl;
	cout << "   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX " << endl << endl;	
}

double eing(string b){
	double a;
	cout << "   Bitte ";
	cout << b;
	cout << " eingeben: ";
	cin >> a;
	// cout << endl;
	return a;
}

// Berrechnung der X-Koordinate
// Alte X-Koordinate, Geschwindigkeit in X-Richtung, Zeitintervall
float x_koord(float x, float vx, float t){
	float xn = x + (vx*t);
	return xn;	
}

//Kollisionsabfrage Vektroriell
// X-Koord K1, Y-Koord K1, Radius K1, X-Koord K2, Y-Koord K2, Radius K2
int koll(float x1, float y1, float r1, float x2, float y2, float r2){
	
	//Vektor K1K2 = OK2-OK1
	//double vk1[2]={x1,y1}	//Vektor OK1 
	//double vk2[2]={x2,y2}	//Vektor OK2
	float vk2k1[2]={x1-x2,y1-y2};
	

	//Betrag vk1k2
	float istb = sqrt(pow(vk2k1[0], 2)+pow(vk2k1[1], 2));
	
	//Prüfung
	float sollb = r1 + r2;
	if (istb <= sollb){
		return true;
	}
	else {
		return false;
	}				
}

float rad(float h, float r1, float r2){
	float w = asin(h/(r1+r2))*180 / PI;
	return w;	

}

float impuls(float m, float v){
	float imp = m*v;
	return imp;	
}

float px(float m, float w){
	float px = m * cos(w);
	return px;
}
float py(float m, float w){
	float py = m* sin(w);
	return py;
}
float betr(float x, float y){
       float a = sqrt(pow(x, 2)+pow(y, 2));
       return a;
}

	

int main(){
	//initialisieren der datei
	fstream f;
	f.open("Test.csv", ios::out);
	
	greet();	
	//Eingabe der Länge l und Breite b des Tisches
	float l = 2; 
	float b = 1;
	
	//Eingabe der Gesamtdauer und des Zeitintervalls
	int D = eing("Simmulationsdauer in Sekunden"); 	
	float t = eing("Zeitintervalldauer in Sekunden"); 	
    float index = 0;
    
    //X-Koord, Y-Koord, Masse, Radius, Geschwindigkeit der Körper 1 und 24
	float k1[6] = {0, 0, eing("Masse K\224rper 1 in Kg"), eing("Radius K\224rper 1 in m"), eing("Geschwindigkeit K\224rper 1 in m/s"), impuls(k1[2],k1[4])};  
	float k2[6] = {l, 0, eing("Masse K\224rper 2 in Kg"), eing("Radius K\224rper 2 in m"), eing("Geschwindigkeit K\224rper 2 in m/s"), impuls(k2[2],k2[4])};
	
	//Versatz eingeben
	float h = eing("Versatz vom mittelpunkt");  
	float w = rad(h,k1[3],k2[3]);

	//Hauptschleife
	while(index < D){
		index = index + t; 						//Aufzählen des Zeitintervalls
		
		//Berrechnung der X-Koordinaten
		k1[0]= x_koord(k1[0], k1[4], t);		
		k2[0]= x_koord(k2[0], k2[4], t);
				
			//Kollisionsabfrage
			if (koll(k1[0], k1[1], k1[3], k2[0], k2[1], k2[3]) == true){
				//cout << index << ", Kollision, " << k1[0] << ", "<< k2[0] <<endl;
				//Aufteilung des Impulses
					//impuls P1 und P2 und Beträge
					float p1[2] = {k1[2]*k1[4],0};
					float p2[2] = {k2[2]*k2[4],0};
					float p1B = betr (p1[0], p1[1]);
					float p2B = betr (p2[0], p2[1]);
					
					//impuls P1_ und P2_ und Beträge
					float p1_[2] = {px(p1B,w),py(p1B,w)};
					float p2_[2] = {px(p2B,w),py(p2B,w)};
					float p1_B = betr (p1_[0],p1_[1]);
					float p2_B = betr (p2_[0],p2_[1]);
				
					//impuls P1__ und P2__ und Beträge
					float p2__[2] = {px(p1_B,w),py(p1_B,w)};
					float p2__[2] = {px(p2_B,w),py(p2_B,w)};
					float p1__B = betr (p1__[0],p1__[1]);
					float p2__B = betr (p2__[0],p2__[1]);
					
					//Impulerhaltung Vektoraddition
					float p_res[2] = {p1_[0]+p2_[0],p1[1]+p2[1]};
					
					float p1Res[2] = {p_res[0] + p1__[0], p_res[1] + p1__[1]};
					float p1Res[2] = {p_res[0] + p2__[0], p_res[1] + p2__[1]};
					
					
			}	
	  	f << "Ausgabe des Textes" << endl; 
		}
	f.close();
	}




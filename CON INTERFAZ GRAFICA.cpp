//#include <allegro.h>
#define MAXFILAS 20 //Eje Y
#define MAXCOLUMNAS 31 //Eje X
using namespace std;

class Mapa{
	private:
		char mapa[MAXFILAS] [MAXCOLUMNAS] = {
			"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"X                          X"
			"XXXXXXXXXXXXXXXXXXXXXXXXXXXXX"

		};
		
	public:
	
};

int main(){
	allegroInit();
	installKeyboard();
	
	setColorDepth(32);
	setGfxMode(GFX_AUTODETECT_WINDOWED, 640, 700, 0, 0);
	
	BITMAP * buffer = create_bitmap(640, 700);
}

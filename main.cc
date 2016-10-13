#include <ctime>
#include <Windows.h>
#include "randomizer.h"

std::string OpenFile() {
	char filepath[MAX_PATH] = "";
	OPENFILENAME open;
	ZeroMemory(&open, sizeof(open));
	open.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	open.hwndOwner = NULL;
	open.lpstrDefExt = "";
	open.lpstrFilter = "All Files (*.*)\0*.*\0";
	open.lpstrFile = filepath;
	open.lStructSize = sizeof(OPENFILENAME);
	open.nMaxFile = MAX_PATH;
	if (GetOpenFileName(&open)) {
		return filepath;
	}
	return "";
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	std::string filepath = OpenFile();
	Bitmap bitmap = RandomizeBitmap(filepath, 45);
	if (bitmap != NULL) {
		SDL_SaveBMP(bitmap, "output.bmp");
	}
	
	return 0;
}
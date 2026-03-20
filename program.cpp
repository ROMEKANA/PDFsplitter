#include "program.h"
#include <filesystem>
#include <cstdlib>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void splitPDF(const string& input){
	fs::path p = fs::absolute(input);

	string dir = p.parent_path().string();
	string name = p.stem().string();

	//string outdir = dir + "\\" + name + "_pages";
	//fs::create_directories(outdir);

	//string output = outdir + "\\page-%02d.pdf";
	string output = dir + "\\" + name + "_page-%02d.pdf";

	string command = "qpdf --split-pages " + input + " " + input;

/*	cout << "Running command: " << command << endl;
	cout << "終了するにはEnterキーを押してください...";
	cin.get();
*/
	system(command.c_str());
}
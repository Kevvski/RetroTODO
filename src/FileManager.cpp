#include "stdafx.h"
#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}


void FileManager::saveToFile(const std::string& fileName, std::vector<TextLine>* tab) {
	file.open(fileName + ".txt", std::ios::out);
	if (file.good()) {
		for (auto it : *tab) {
			if(it.isDone())
				file << "1" + it.getText() + "\n";
			else
				file << "0" + it.getText() + "\n";
		}
		file.close();
		std::cout << "Save to file: " << fileName << ".txt success!" << std::endl;
		Sleep(1500);
	}
}


bool FileManager::loadFromFile(const std::string& fileName, std::vector<TextLine>* tab) {
	std::string* text = new std::string();
	TextLine* textLine = new TextLine();

	file.open(fileName + ".txt", std::ios::in);
	if (file.good()) {

		while (!file.eof()) {
			std::getline(file, *text);
			if (!text->empty()) {

				if (text->at(0) == '1') {
					textLine->setDone();
					textLine->setColor(10);
					text->erase(text->begin());
				}
				else if(text->at(0) == '0') {
					textLine->setNotDone();
					textLine->setColor(12);
					text->erase(text->begin());
				}

				textLine->setText(*text);
				tab->push_back(*textLine);
			}
		}
		file.close();

		std::cout << "Load file: " << fileName << ".txt success!" << std::endl;
		Sleep(1500);
		delete text;
		delete textLine;
		return true;
	}
	else {
		std::cout << "Open file: " << fileName << " failure!" << std::endl;
		Sleep(1500);
		delete text;
		delete textLine;
		return false;
	}
}


std::string FileManager::convertToString(int value) const {
	std::ostringstream os;
	os << value;
	return os.str();
}

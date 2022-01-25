#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "TextLine.h"
#include "State.h"

class FileManager
{
public:
	FileManager();
	~FileManager();

	void saveToFile(const std::string& fileName, std::vector<TextLine>* tab);
	bool loadFromFile(const std::string& fileName, std::vector<TextLine>* tab);

private:
	std::fstream file;

private:
	std::string convertToString(int value) const;
};

#endif FILEMANAGER_H

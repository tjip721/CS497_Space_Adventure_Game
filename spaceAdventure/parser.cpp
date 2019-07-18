#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Parser.hpp"

Parser::Parser() {
	currentTokenIndex = 0;
}

int Parser::loadFiles(std::string verbFileList, std::string nounFileList) {
	int result;
	result = loadFileList(verbFileList, verbLists);
	if (result == EXIT_FAILURE) {
		return result;
	}
	result = loadFileList(nounFileList, nounLists);
	if (result == EXIT_FAILURE) {
		return result;
	}
}

int Parser::loadFileList(std::string fileListName, std::vector< std::vector<std::string> > &wordLists) {
    std::string fileName;
	int result;
    int listCount = 0;
	std::ifstream file(fileListName.c_str());
	if (!file) {
		std::cerr << "Failed to open file: " << fileListName;
		return EXIT_FAILURE;
	}
	while (getline(file, fileName)) {
		std::vector<std::string> newList;
		wordLists.push_back(newList);
		result = loadFile(fileName, wordLists[listCount]);
		if (result == EXIT_FAILURE) {
			return result;
		}
		listCount++;
	}
	file.close();
	return EXIT_SUCCESS;
}

int Parser::loadFile(std::string fileName, std::vector<std::string> &wordList) {
    std::string word;
	std::ifstream file(fileName.c_str());
	if (!file) {
		std::cerr << "Failed to open file: " << fileName;
		return EXIT_FAILURE;
	}
    while (getline(file, word)) {
        wordList.push_back(word);
    }
    file.close();
	return EXIT_SUCCESS;
}

void Parser::processInput(std::string i) {
	// Reset members
	inputTokens.clear();
	verb.clear();
	nouns.clear();
	currentTokenIndex = 0;

	// Process new input
	input = i;
    inputToLowerCase();
    tokenizeInput();
	matchVerb();
	matchNouns();
	duplicateNounCheck();
}

void Parser::inputToLowerCase() {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
}

void Parser::tokenizeInput() {
    std::stringstream inputStringStream(input);
    std::string temp;
    while (std::getline(inputStringStream, temp, ' ')) {
        inputTokens.push_back(temp);
    }
}

void Parser::matchVerb() {
    for (int i = 0; i < inputTokens.size(); i++) {
        currentTokenIndex++;
        for (std::vector<std::string> list : verbLists) {
            if (searchList(inputTokens[i], list)) {
                verb = list[0];
                return;
            }
        }
    }
}

void Parser::matchNouns() {
    if (currentTokenIndex < inputTokens.size()) {
        for (int i = currentTokenIndex; i < inputTokens.size(); i++) {
            for (std::vector<std::string> list : nounLists) {
                if (searchList(inputTokens[i], list)) {
                    nouns.push_back(list[0]);
                    if (nouns.size() == 2) {
                        return;
                    }
                }
            }
        }
    }
}

bool Parser::searchList(std::string token, std::vector<std::string> &list) {
    int index = lower_bound(std::next(list.begin(), 1), list.end(), token) - list.begin();
    if (index < list.size() && list[index] == token) {
        return true;
    }
    return false;
}

void Parser::duplicateNounCheck() {
	if (nouns.size() > 1 && nouns[0] == nouns[1]) {
		nouns.pop_back();
	}
}

std::string Parser::getVerb() {
    return verb;
}

const std::vector<std::string>& Parser::getNouns() const {
    return nouns;
}

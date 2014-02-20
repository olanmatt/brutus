#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void swap(char *x, char *y){
	char w;
	w = *x;
	*x = *y;
	*y = w;
}

void prnt(char *str, int *per){
	for(int i = 0; per[i] != -1; i++)
		printf("%c", str[per[i]]);
	printf("\n");
}

unsigned int GetFileLen(FILE* file){
	unsigned int pos = ftell(file);
	fseek(file, 0, SEEK_END);
	unsigned int len = ftell(file);
	fseek(file, pos, SEEK_SET);
	return len;
}

string TrimString(string s){
	while (s.size() > 0){
		if (s[0] == ' ' || s[0] == '\t')
			s = s.substr(1);
		else
			break;
	}

	while (s.size() > 0){
		if (s[s.size() - 1] == ' ' || s[s.size() - 1] == '\t')
			s = s.substr(0, s.size() - 1);
		else
			break;
	}

	return s;
}

bool ReadLinesFromFile(string sPathName, vector<string>& vLine){
	vLine.clear();

	FILE* file = fopen(sPathName.c_str(), "rb");
	if (file != NULL){
		unsigned int len = GetFileLen(file);
		char* data = new char[len + 1];
		fread(data, 1, len, file);
		data[len] = '\0';
		string content = data;
		content += "\n";
		delete data;

		int i;
		for (i = 0; i < content.size(); i++){
			if (content[i] == '\r')
				content[i] = '\n';
		}

		int n;
		while ((n = content.find("\n", 0)) != -1){
			string line = content.substr(0, n);
			line = TrimString(line);
			if (line != "")
				vLine.push_back(line);
			content = content.substr(n + 1);
		}

		fclose(file);
	}
	else
		return false;

	return true;
}

bool SeperateString(string s, string sSeperator, vector<string>& vPart){
	vPart.clear();

	int i;
	for (i = 0; i < sSeperator.size(); i++){
		int n = s.find(sSeperator[i]);
		if (n != -1){
			vPart.push_back(s.substr(0, n));
			s = s.substr(n + 1);
		}
		else
			return false;
	}
	vPart.push_back(s);

	return true;
}

int loadCharset(int setname, char charset[], int *setlen){ //string sName){

	string sName = "alpha"; // TODO parse name

	if (sName == "byte"){
		// TODO printf will not print 0x00
		for (int i = 0x00; i <= 0xff; i++){
			charset[i] = i;
		}
		*setlen = 256;
		return 0;
	}

	vector<string> vLine;
	if (ReadLinesFromFile("charset.txt", vLine)){
		int i;
		for (i = 0; i < vLine.size(); i++){
			// Filter comment
			if (vLine[i][0] == '#')
				continue;

			vector<string> vPart;
			if (SeperateString(vLine[i], "=", vPart)){
				
				// sCharsetName
				string sCharsetName = TrimString(vPart[0]);
				if (sCharsetName == "")
					continue;

				// sCharsetName charset check
				bool fCharsetNameCheckPass = true;
				int j;
				for (j = 0; j < sCharsetName.size(); j++){
					if (   !isalpha(sCharsetName[j])
							&& !isdigit(sCharsetName[j])
							&& (sCharsetName[j] != '-')){
						fCharsetNameCheckPass = false;
						break;
					}
				}
				
				if (!fCharsetNameCheckPass){
					printf("invalid charset name %s in charset configuration file\n", sCharsetName.c_str());
					continue;
				}

				// sCharsetContent
				string sCharsetContent = TrimString(vPart[1]);
				if (sCharsetContent == "" || sCharsetContent == "[]")
					continue;
				if (sCharsetContent[0] != '[' || sCharsetContent[sCharsetContent.size() - 1] != ']'){
					printf("invalid charset content %s in charset configuration file\n", sCharsetContent.c_str());
					continue;
				}
				sCharsetContent = sCharsetContent.substr(1, sCharsetContent.size() - 2);
				if (sCharsetContent.size() > 256){
					printf("charset content %s too long\n", sCharsetContent.c_str());
					continue;
				}

				printf("%s = [%s]\n", sCharsetName.c_str(), sCharsetContent.c_str());

				// Is it the wanted charset?
				if (sCharsetName == sName){
					*setlen = strlen(sCharsetContent.c_str()); //sCharsetContent.size();
					memcpy(charset, sCharsetContent.c_str(), strlen(sCharsetContent.c_str()));
					return 0;
				}
			}
		}
		printf("charset %s not found in charset.txt\n", sName.c_str());
	}
	else
		printf("can't open charset configuration file\n");
	return 1;
}

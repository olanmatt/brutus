/*
 *	RainbowCrack - a general propose implementation of Philippe Oechslin's faster time-memory trade-off technique.
 *	Copyright (C) Zhu Shuanglei <shuanglei@hotmail.com>
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////////

using namespace std;

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

bool LoadCharset(string sName){

	unsigned char m_PlainCharset[256];
	int m_nPlainCharsetLen;
	string m_sPlainCharsetName;
	string m_sPlainCharsetContent;

	if (sName == "byte"){
		for (int i = 0x00; i <= 0xff; i++)
			m_PlainCharset[i] = i;
		m_nPlainCharsetLen = 256;
		m_sPlainCharsetName = sName;
		m_sPlainCharsetContent = "0x00, 0x01, ... 0xff";
		return true;
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
					m_nPlainCharsetLen = sCharsetContent.size();
					memcpy(m_PlainCharset, sCharsetContent.c_str(), m_nPlainCharsetLen);
					m_sPlainCharsetName = sCharsetName;
					m_sPlainCharsetContent = sCharsetContent;
					return true;
				}
			}
		}
		printf("charset %s not found in charset.txt\n", sName.c_str());
	}
	else
		printf("can't open charset configuration file\n");

	return false;
}

int main(){
	LoadCharset("mixalpha-numeric-all-space");
}

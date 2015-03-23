#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <unordered_map>

#include "cJSON.h"
#include "cJSON.c"

void GetMessage(char *json, char *msg)
{
	cJSON *root = cJSON_Parse(json);
	msg = cJSON_GetObjectItem(root, "text")->valuestring;
}

int main(int argc, char *argv[])
{
	std::string app_path = "open";

	std::string str = "{ \"text\": \"on\"}";
	unsigned int str_sz = str.length();
	std::cout.write((char *)&str_sz, 4);
	std::cout.write(str.c_str(), str_sz);

	char input_buffer[256];
	std::cin.read(input_buffer, 256);

	char *buffer;
	GetMessage(input_buffer, buffer);


	char exec_app[] = "App Store\0";
	char exec_string[256];
	snprintf((char *)&exec_string[0], 256, "/Applications/%s.app/", buffer);

	if(execl("/usr/bin/open", "open", (char *)&exec_string[0], NULL) < 0)
	{
		std::cout << "ERROR: " << errno << std::endl;
		return 1;
	}

	return 0;
}
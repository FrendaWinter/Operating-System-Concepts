#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ReadFileContent(const std::string &filePath, std::vector<char> &fileContent)
{
	// Open the file
	HANDLE hFile = CreateFile(
		filePath.c_str(),	   // File name
		GENERIC_READ,		   // Desired access
		FILE_SHARE_READ,	   // Share mode
		nullptr,			   // Security attributes
		OPEN_EXISTING,		   // Open existing file
		FILE_ATTRIBUTE_NORMAL, // File attributes
		nullptr				   // Template file handle
	);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::wcerr << L"Failed to open file. Error: " << GetLastError() << std::endl;
		return;
	}

	// Buffer to store file content
	const DWORD bufferSize = 1024; // 1 KB buffer size
	char buffer[bufferSize];
	DWORD bytesRead;

	// Read the file content
	while (ReadFile(hFile, buffer, bufferSize, &bytesRead, nullptr) && bytesRead > 0)
	{
		std::cout << "Read " << bytesRead << " bytes." << endl;
		fileContent.insert(fileContent.end(), buffer, buffer + bytesRead);
	}

	// Close the file
	CloseHandle(hFile);

	return;
}

void writeFileContent(const std::string &filePath, const std::vector<char> &fileContent)
{
	// Write the file content to the output file
	HANDLE hFile = CreateFile(
		filePath.c_str(),
		GENERIC_WRITE,
		0,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::wcerr << L"Failed to create file. Error: " << GetLastError() << std::endl;
		return;
	}

	DWORD bytesWritten;
	WriteFile(hFile, fileContent.data(), fileContent.size(), &bytesWritten, nullptr);

	CloseHandle(hFile);
}

int main(int argc, char *argv[])
{
	// Check if a file path is provided
	if (argc < 3)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file_path> <output_file_path>" << std::endl;
		return 1;
	}

	std::string inputFilePath = argv[1];

	// Read the file content
	std::vector<char> fileContent;
	ReadFileContent(inputFilePath, fileContent);

	// Write the file content to the output file
	std::string outputFilePath = argv[2];
	writeFileContent(outputFilePath, fileContent);

	return 0;
}

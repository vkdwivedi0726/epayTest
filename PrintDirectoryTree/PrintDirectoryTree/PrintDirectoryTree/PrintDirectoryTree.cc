#include "PrintDirectoryTree.h"

#include <deque>

int PrintDirectoryTree(const TCHAR* path) {

	int lineCount = 0;

	std::deque<std::basic_string<TCHAR>> path_q;
	path_q.clear();
	path_q.emplace_back(path);

	while (!path_q.empty()) {
		const TCHAR* current_dir = path_q.front().c_str();
		path_q.pop_front();

		WIN32_FIND_DATA find_file_data;
		TCHAR search_path[MAX_PATH];

		_stprintf_s(search_path, MAX_PATH, _T("%s\\*"), current_dir);
		HANDLE file_handle = FindFirstFile(search_path, &find_file_data);

		if (file_handle != INVALID_HANDLE_VALUE) {
			do {
				if (_tcscmp(find_file_data.cFileName, _T(".")) != 0 && _tcscmp(find_file_data.cFileName, _T("..")) != 0) {
					_tprintf(_T("Line %d: %s\\%s\n"), ++lineCount, current_dir, find_file_data.cFileName);

					if (find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
						TCHAR newPath[MAX_PATH];
						_stprintf_s(newPath, MAX_PATH, _T("%s\\%s"), current_dir, find_file_data.cFileName);
						path_q.emplace_back(newPath);
					}
				}
			} while (FindNextFile(file_handle, &find_file_data) != 0);

			FindClose(file_handle);
		}
	}

	return lineCount;
}


int main() {
	const TCHAR* startPath = _T("C:\\windows\\debug");
	int lineCount = PrintDirectoryTree(startPath);

	_tprintf(_T("Result (line count = %d)\n"), lineCount);
	std::cin.get();

	return 0;
}

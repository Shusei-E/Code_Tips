#pragma once
#include <stdio.h>
#include <dirent.h>
#include <vector>
using namespace std;

class FilesList{
public:
  vector<string> files_list; // stores path to the files we want to use
  int file_num;

  FilesList(string &folder_path){
    files_list = getFileList(folder_path);
  }

  vector<string> getFileList(const string &folder_path) {
    // Get File list: http://xr0038.hatenadiary.jp/entry/2015/02/26/154608sR
    
    DIR *dp;       // pointer to the directory
    dirent* entry; // readdir() returns this entry point 
  
    dp = opendir(folder_path.c_str()); // don't forget to change string to const* char
    vector<string> path_list;
    if (dp==NULL){
      cout << "Error occured in FilesList. Something is wrong with the folder path" << endl;
      exit(1);
    }
    do {
      entry = readdir(dp);
      if (entry != NULL){
        if(has_suffix(entry->d_name, ".txt"))
          path_list.push_back(folder_path + entry->d_name); // make full path
          ++file_num;
      }
    } while (entry != NULL);
    
    return path_list;
  }

  bool has_suffix(const string& s, const string& suffix){ // check suffix
      return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());    
  }

};

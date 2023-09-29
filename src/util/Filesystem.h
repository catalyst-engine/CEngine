#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

namespace Util::FS{
    std::string write_file(std::string filename,std::string filecontent, std::filesystem::path file_path){
        std::ofstream file;
        file_path /= filename;
        file.open(file_path.string());
        if(file.is_open()){
            file << filecontent;
            file.close();
            return "0";
        }
        else{
            return "-1";
        }
    }
    std::string read_file(std::string filename, std::filesystem::path file_path){
        std::fstream file;
        std::string line;
        std::string text = "";
        file_path /= filename;
        file.open(file_path.string());
        if(file.is_open()){
            while ( file ) {
                std::getline(file, line);
                text += std::string(line);
            }
            file.close();
            return text;
        }
        else{
            return "-1";
        }
    }
    bool rename_file(std::string filename, std::filesystem::path file_path, std::string new_name){
        std::filesystem::path new_file_path = file_path;
        new_file_path /= new_name;
        file_path /= filename;
        if(std::filesystem::exists(new_file_path)){
            return "File already exists";
        }
        rename(file_path,new_file_path);
        if(std::filesystem::exists(new_file_path)){
            return true;
        }else{
            return false;
        }
    }
    bool delete_file(std::string filename, std::filesystem::path file_path){
        file_path /= filename;
        if(std::filesystem::exists(file_path)){
            if(remove(file_path) == 0){
                   return true;
            }
            return false;
        }
        return "File does not exist";
    }
}
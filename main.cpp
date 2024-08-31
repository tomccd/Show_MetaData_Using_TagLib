#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <experimental/filesystem>
#include <iostream>

namespace fs=std::experimental::filesystem;

std::string getFile(std::string dir){
    if(fs::is_directory(dir)){
        for(auto &file: fs::directory_iterator(dir)){
            std::cout << file.path() << std::endl;
            if(file.path().extension() == ".mp3"){
                return file.path().string();
            }
        }
    }
    return "";
}

int main() {
    // Path to your directory
    std::cout << getFile("${HOME}/Downloads/");
    TagLib::FileRef file(getFile("/home/tomccd/Downloads").c_str());
    TagLib::Tag * tag = file.tag();
    if(!tag->isEmpty()){
        std::cout << "Artist: " << tag->artist() << std::endl;
        std::cout << "Title: "    << tag->title() << std::endl;
        std::cout << "Album: " << tag->album() << std::endl;
    }
}

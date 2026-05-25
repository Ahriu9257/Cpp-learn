//
// Created by ahriu on 2026/5/24.
//
#include "FileHandle.h"

#include <iostream>
#include <ostream>
#include <stdexcept>

FileHandle::FileHandle(const std::string& filename,const std::string& mode)
    : fp_(nullptr),filename_(filename)
{
    fp_ = std::fopen(filename.c_str(),mode.c_str());

    if (fp_ == nullptr)
    {
        throw std::runtime_error(std::string("Cannot open file: ")+filename);
    }

    std::cout << "File opened:" << this->filename_ << std::endl;
}

FileHandle::~FileHandle()
{
    if (fp_ != nullptr)
    {
        std::fclose(fp_);
        std::cout << "File closed:" << this->filename_ << std::endl;
        fp_ = nullptr;
    }
}

void FileHandle::write(const std::string& text)
{
    if (fp_ == nullptr)
    {
        throw std::runtime_error(std::string("Cannot write to file: ")+this->filename_);
    }
    std::fputs(text.c_str(),fp_);
}

bool FileHandle::is_open() const
{
    return fp_ != nullptr;
}

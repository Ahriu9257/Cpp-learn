//
// Created by ahriu on 2026/5/24.
//

#ifndef CH06SENSORS_FILEHANDLE_H
#define CH06SENSORS_FILEHANDLE_H

#pragma once
#include <cstdio>
#include <string>

class FileHandle
{
public:

  FileHandle(const std::string& filename,const std::string& mode);

  ~FileHandle();

  FileHandle(const FileHandle&) = delete;
  FileHandle& operator=(const FileHandle&) = delete;

  void write(const std::string& text);

  bool is_open() const;

private:
  FILE* fp_;
  std::string filename_;
};

#endif //CH06SENSORS_FILEHANDLE_H

#include "file_writer.h"

#include <fstream>
#include <string>
#include <vector>

FileWriter::FileWriter(std::string output_filename)
    : ofstream_(output_filename) {}

template <typename T> void FileWriter::Write(T value, char separator) {
  if constexpr (std::is_same_v<std::decay_t<T>, int>) {
    WriteInt(value, separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>, std::vector<int>>) {
    WriteVectorInt(value, ' ', separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>,
                                      std::vector<std::pair<int, int>>>) {
    WriteVectorPair(value, ' ', separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
    WriteString(value, separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>, const char*>) {
    WriteString(value, separator);
  }
}

template void FileWriter::Write<int>(int, char);
template void FileWriter::Write<std::vector<int>>(std::vector<int>, char);
template void FileWriter::Write<std::string>(std::string, char);
template void FileWriter::Write<const char*>(const char*, char);
template void FileWriter::Write<std::vector<std::pair<int, int>>>(
  std::vector<std::pair<int, int>>, char);

template <typename T> void FileWriter::Write(T value, char middle_separator,
                                             char end_separator) {
  if constexpr (std::is_same_v<std::decay_t<T>, int>) {
    WriteInt(value, end_separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>, std::vector<int>>) {
    WriteVectorInt(value, middle_separator, end_separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>,
                                      std::vector<std::pair<int, int>>>) {
    WriteVectorPair(value, middle_separator, end_separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
    WriteString(value, end_separator);
  } else if constexpr (std::is_same_v<std::decay_t<T>, const char*>) {
    WriteString(value, end_separator);
  }
}

template void FileWriter::Write<int>(int, char, char);
template void FileWriter::Write<std::vector<int>>(std::vector<int>, char, char);
template void FileWriter::Write<std::string>(std::string, char, char);
template void FileWriter::Write<const char*>(const char*, char, char);
template void FileWriter::Write<std::vector<std::pair<int, int>>>(
  std::vector<std::pair<int, int>>, char, char);

FileWriter::~FileWriter() { ofstream_.close(); }

void FileWriter::WriteInt(int value, char end_separator) {
  ofstream_ << value << end_separator;
}

void FileWriter::WriteVectorInt(std::vector<int> values, char middle_separator,
                                char end_separator) {
  for (int i = 0; i < values.size(); i++) {
    if (i > 0) {
      ofstream_ << middle_separator;
    }
    ofstream_ << values[i];
  }
  ofstream_ << end_separator;
}

void FileWriter::WriteVectorPair(std::vector<std::pair<int, int>> values,
                                 char middle_separator, char end_separator) {
  for (int i = 0; i < values.size(); i++) {
    if (i > 0) {
      ofstream_ << middle_separator;
    }
    ofstream_ << values[i].first << " " << values[i].second;
  }
  ofstream_ << end_separator;
}

void FileWriter::WriteString(std::string message, char end_separator) {
  ofstream_ << message << end_separator;
}
#ifndef TEST_GENERATOR_LIB_FILE_WRITER_H
#define TEST_GENERATOR_LIB_FILE_WRITER_H

#include <fstream>
#include <string>
#include <vector>

class FileWriter {
 public:
  FileWriter(std::string output_filename);

  template <typename T> void Write(T value, char separator);

  template <typename T> void Write(T value, char middle_separator,
                                   char end_separator);

  ~FileWriter();

 private:
  void WriteInt(int value, char end_separator);

  void WriteVectorInt(std::vector<int> values, char middle_separator,
                      char end_separator);

  void WriteVectorPair(std::vector<std::pair<int, int>> values,
                       char middle_separator, char end_separator);

  void WriteString(std::string message, char end_separator);

  std::ofstream ofstream_;
};

#endif  // TEST_GENERATOR_LIB_FILE_WRITER_H
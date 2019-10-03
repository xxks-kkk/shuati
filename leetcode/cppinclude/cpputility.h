#include "shared_headers.h"

#ifndef SHUATI_UTILITY_H
#define SHUATI_UTILITY_H

// cpp: we can add our own message during the compilation
//#pragma message "We use utiltiy.h from cppinclude"
//#warning "We use correct utility.h"

namespace CPPUtility
{
  // Use anoymous namespace to keep private stuff in the namespace
  // ref: https://www.internalpointers.com/post/c-namespaces-private-members
  namespace {
    // https://stackoverflow.com/questions/15118661/in-c-whats-the-fastest-way-to-tell-whether-two-string-or-binary-files-are-di
    template<typename InputIterator1, typename InputIterator2>
    bool
    range_equal(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2)
    {
      while(first1 != last1 && first2 != last2)
      {
        if(*first1 != *first2) return false;
        ++first1;
        ++first2;
      }
      return (first1 == last1) && (first2 == last2);
    }
  }
  
  // split the string by the given delimiter
  std::vector <std::string>
  split(const std::string &str, const std::string &delim);

  // convert the vector<string> to vector<int>
  std::vector<int>
  convertToInt(const std::vector<std::string>& input);

  // generate string representation of the given 2D vectors (e.g., matrix)
  template <typename T>
  std::string twoDVectorStr(std::vector<std::vector<T>> matrix)
  {
    std::string cand = "\n[";
    for(int j = 0; j < matrix.size(); ++j)
    {
      j == 0 ? cand += "[" : cand += " [";
      int i;
      auto vec = matrix[j];
      for(i = 0; i < vec.size(); ++i)
      {
        // TODO: https://www.fluentcpp.com/2017/06/06/using-tostring-custom-types-cpp/
        // Assume T has implemented / overridden the to_string method
        cand += std::to_string(vec[i]);
        i != vec.size() - 1 ? cand += "," : cand += "";
      }
      j == matrix.size() - 1 ? cand += "]" : cand += "]\n";
    }
    cand += "]\n";
    return cand;
  }

  // pretty print 2D vector
  template <typename T>
  void prettyPrint2DVector(std::ostream& theStream, std::vector<std::vector<T>> matrix)
  {
    auto rep = twoDVectorStr(matrix);
    theStream << rep;
  }

  template <typename T>
  std::string oneDVectorStr(const std::vector<T>& vec) {
    std::string cand = "[";
    for(int i = 0; i < vec.size(); ++i) {
      cand += std::to_string(vec[i]);
      i != vec.size() - 1 ? cand += "," : cand += "";
    }
    cand += "]";
    return cand;
  }

  // return string representation of vector<pair<T,U>>
  template <typename T, typename U>
  std::string oneDVectorPairStr(const std::vector<std::pair<T,U>>& vec) {
    std::string tmp = "";
    for(int i = 0; i < vec.size(); ++i) {
      tmp += "(";
      tmp += std::to_string(vec[i].first);
      tmp += ",";
      tmp += std::to_string(vec[i].second);
      tmp += ")";
    }
    return tmp;
  }

  // compare given two files to see if they are equal
  bool compare_files(const std::string& filename1, const std::string& filename2)
  {
    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    std::istreambuf_iterator<char> end;

    return range_equal(begin1, end, begin2, end);
  }
}

#endif

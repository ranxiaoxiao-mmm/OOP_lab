# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-src"
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-build"
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix"
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix/tmp"
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp"
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix/src"
  "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Archive/subject/two two/OOP/lab/lab6/lab6/build/_deps/gtest-subbuild/gtest-populate-prefix/src/gtest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

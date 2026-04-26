# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-src")
  file(MAKE_DIRECTORY "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-build"
  "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix"
  "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix/tmp"
  "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
  "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src"
  "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/nadas/Desktop/programming/C++/finance_tracker_refined/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

/*************************************************************************
POMATO: POincare MAp TOpology: Extraction and visualization of the
        topological structure of the circular restricted three-body 
        problem for orbital mechanics applications. 

Authors: Wayne Schlei and Xavier Tricoche 

Copyright (c) 2013-2018, Purdue University 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
**************************************************************************/


#ifndef __XAVIER_FILENAME_HPP__
#define __XAVIER_FILENAME_HPP__

#include <string>

namespace {
    std::string __before_char(const std::string& str, char c) {
        size_t n = str.find_last_of(c);
        if (n == std::string::npos) return str;
        else return str.substr(0, n);
    }
    std::string __after_char(const std::string& str, char c) {
        size_t n = str.find_last_of(c);
        if (n == std::string::npos) return "";
        else return str.substr(n+1);
    }
    void __around_char(std::string& before, std::string& after, const std::string& str, char c) {
        size_t n = str.find_last_of(c);
        if (n == std::string::npos) {
            before = str;
            after = "";
        }
        else {
            before = str.substr(0, n);
            after = str.substr(n+1);
        }
    }
}

// basic helper functions to manipulate file names
namespace xavier { namespace filename {
    
inline std::string parent_path(const std::string& name) {
    return __before_char(name, '/');
}

inline std::string extension(const std::string& name)
{
    return __after_char(name, '.');
}

inline std::string filename(const std::string& name) {
    return __after_char(name, '/');
}

inline std::string remove_extension(const std::string& name)
{
    return __before_char(name, '.');
}

inline std::string replace_extension(const std::string& name, const std::string& ext)
{
    return remove_extension(name) + '.' + ext;
}

} // filename 
} // xavier

#endif
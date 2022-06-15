//
// Created by Nadav Koplovich on 08/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

#include <string>

using std::string;

class DeckFileNotFound : public std::exception
{
    public:
    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public  std::runtime_error
{
    //const std::string message = "Deck File Error: File format error in line ";

    //int m_line;

    public:
    DeckFileFormatError(int line):
        std::runtime_error("Deck File Error: File format error in line " + std::to_string(line))
        //m_line(line)
    {}

    const char * what() const noexcept override
    {
        return runtime_error::what();
    }
};

class DeckFileInvalidSize : public std::exception
{
    public:
    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif //EX4_EXCEPTION_H
